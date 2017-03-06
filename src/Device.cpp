/*
 * Devic.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */



#include <lrand/lrand.h>

#define LONGITUDE	-79.395299
#define LATITUDE	43.661793
#define DIRECTION	-90

std::string Device::battery_state 			= "charging";
std::atomic<double> Device::battery_life;


// system gps variables
extern std::atomic<double>	location_changed;

// system vector variables
extern std::atomic<double> 	direction_changed;

// system battery variables
extern std::atomic<bool>	EXIT_THREADS;

double prev_lat,prev_dir;
unsigned char buf[80];
int bfd,rdlen,split2;
std::string s;

void getCoords(){
	if (User::m_latitude == (double)0.0){
	User::m_latitude 	= LATITUDE;
	User::m_longitude = LONGITUDE;
	}
	if (User::m_latitude != prev_lat){
		location_changed = true;
		prev_lat = User::m_latitude;
	}
}

void getDirection(){
	if (User::m_direction < -180){
		User::m_direction = 179;
	}
	else
	if (User::m_direction > 180){
		User::m_direction = -179;
	}
	if (User::m_direction != prev_dir){
		direction_changed = true;
		prev_dir = User::m_direction;
	}
	if (User::m_pitch < -180){
		User::m_pitch = 179;
	}
	else
	if (User::m_pitch > 180){
		User::m_pitch = -179;
	}
}

double sightLine(){
	return 20000.0;
}

void getInformation(){
		rdlen = read(bfd, buf, sizeof(buf) - 1);
		s = std::string((char*)buf);
		if (rdlen > 0) {
			switch(buf[0]){
			case '!':
				Device::battery_state = s.substr(1);
				break;
			case '#':
				Device::battery_life = std::atof(s.substr(1).c_str());
				break;
			case 'H':
				User::m_direction	= std::atof(s.substr(1).c_str());
				break;
			case 'P':
				User::m_pitch	= std::atof(s.substr(1).c_str());
				break;
			case 'R':
				User::m_roll	= std::atof(s.substr(1).c_str());
				break;
			case 'L':
				split2 = s.substr(1).find('@');
				User::m_longitude	= std::atof(s.substr(1,split2).c_str());
				User::m_latitude = std::atof(s.substr(split2+2,s.substr(split2+2).find('@')).c_str());
				User::m_altitude = std::atof(s.substr(s.substr(split2+2).find('@')).c_str());
				break;
			}
		} else if (rdlen < 0) {
			printf("Error from read: %d: %s\n", rdlen, strerror(errno));
		}
}


int
Device::set_interface_attribs (int fd, int speed, int parity)
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
Device::set_blocking (int fd, int should_block)
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


int Device::setPort(std::string s){
	closePort();
	portname = (char*)s.c_str();
	openPort();
	return 0;
}

std::string Device::getPort(void){
	return std::string(portname);
}

int Device::openPort(void){
	fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0)
	{
			std::fprintf(stderr,"error %d opening %s: %s", errno, portname, strerror (errno));
			return -1;
	}

	return 0;
}

int Device::closePort(void){
	return close(fd);
}

Device::Device() {

	portname = "/dev/ttyUSB0";

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

Device::~Device() {
	closePort();
	// TODO Auto-generated destructor stub
}

