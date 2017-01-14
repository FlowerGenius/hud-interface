################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../rpi/src/context.cpp \
../rpi/src/main.cpp \
../rpi/src/platform_rpi.cpp 

OBJS += \
./rpi/src/context.o \
./rpi/src/main.o \
./rpi/src/platform_rpi.o 

CPP_DEPS += \
./rpi/src/context.d \
./rpi/src/main.d \
./rpi/src/platform_rpi.d 


# Each subdirectory must supply rules for building sources it contributes
rpi/src/%.o: ../rpi/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


