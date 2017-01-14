################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tizen/src/platform_gl.cpp \
../tizen/src/platform_tizen.cpp \
../tizen/src/urlWorker.cpp 

OBJS += \
./tizen/src/platform_gl.o \
./tizen/src/platform_tizen.o \
./tizen/src/urlWorker.o 

CPP_DEPS += \
./tizen/src/platform_gl.d \
./tizen/src/platform_tizen.d \
./tizen/src/urlWorker.d 


# Each subdirectory must supply rules for building sources it contributes
tizen/src/%.o: ../tizen/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


