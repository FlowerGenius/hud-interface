/*
 * DeviceAccess.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */


#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <header.h>
#include <DeviceAccess.h>

#define LONGITUDE	-79.395293
#define LATITUDE	43.661802
#define DIRECTION	-90

// system gps variables
extern std::atomic<double> 	m_latitude;
extern std::atomic<double> 	m_longitude;
extern std::atomic<double>	m_altitude;

extern std::atomic<double>	location_changed;

// system vector variables
extern std::atomic<double>	m_direction;
extern std::atomic<double> 	direction_changed;

// system battery variables
extern std::atomic<double> 	dev_battery_life;
extern std::atomic<bool> 	dev_is_charging;
extern std::string			dev_battery_state;

extern std::atomic<bool>	EXIT_THREADS;

double prev_lat,prev_dir;
unsigned char buf[80];
int bfd,rdlen,split2;
std::string s;

void getCoords(){
	if (m_latitude == (double)0.0){
	m_latitude 	= LATITUDE;
	m_longitude = LONGITUDE;
	}
	if (m_latitude != prev_lat){
		location_changed = true;
		prev_lat = m_latitude;
	}
}

void getDirection(){
	if (m_direction < -180){
		m_direction = 179;
	}
	else
	if (m_direction > 180){
		m_direction = -179;
	}
	if (m_direction != prev_dir){
		direction_changed = true;
		prev_dir = m_direction;
	}
}

double sightLine(){
	return 200.0;
}

void getInformation(){
		rdlen = read(bfd, buf, sizeof(buf) - 1);
		s = std::string((char*)buf);
		if (rdlen > 0) {
			switch(buf[0]){
			case '!':
				split2 = s.substr(1).find('@');
				dev_battery_state = s.substr(1,split2);
				dev_battery_life = std::atof(s.substr(split2+2).c_str());
				break;
			case '*':
				m_direction = std::atof(s.substr(1).c_str());
				break;
			case 'L':
				split2 = s.substr(1).find('@');
				m_longitude	= std::atof(s.substr(1,split2).c_str());
				m_latitude = std::atof(s.substr(split2+2,s.substr(split2+2).find('@')).c_str());
				m_altitude = std::atof(s.substr(s.substr(split2+2).find('@')).c_str());
				break;
			}
		} else if (rdlen < 0) {
			printf("Error from read: %d: %s\n", rdlen, strerror(errno));
		}
}


int
DeviceAccess::set_interface_attribs (int fd, int speed, int parity)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                std::fprintf(stderr,"error %d from tcgetattr", errno);
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                std::fprintf(stderr,"error %d from tcsetattr", errno);
                return -1;
        }
        return 0;
}

void
DeviceAccess::set_blocking (int fd, int should_block)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                std::fprintf(stderr,"error %d from tggetattr", errno);
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
                std::fprintf(stderr,"error %d setting term attributes", errno);
}


int DeviceAccess::setPort(std::string s){
	closePort();
	portname = (char*)s.c_str();
	openPort();
	return 0;
}

std::string DeviceAccess::getPort(void){
	return std::string(portname);
}

int DeviceAccess::openPort(void){
	fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0)
	{
			std::fprintf(stderr,"error %d opening %s: %s", errno, portname, strerror (errno));
			return -1;
	}

	return 0;
}

int DeviceAccess::closePort(void){
	return close(fd);
}

DeviceAccess::DeviceAccess() {

	portname = "/dev/stdin";
	openPort();
	set_interface_attribs (fd, B115200, 0);  // set speed to 115,200 bps, 8n1 (no parity)
	set_blocking (fd, 0);                // set no blocking

	int k;
	do {
		k = write (fd, greet, 2);
	} while(k!=2);

	usleep ((2 + 25) * 100);             // sleep enough to transmit the 2 plus
	                                     // receive 25:  approx 100 uS per char transmit

	bfd = fd;
}

DeviceAccess::~DeviceAccess() {
	closePort();
	// TODO Auto-generated destructor stub
}

