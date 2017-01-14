################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/src/catch.cpp \
../tests/src/gl_mock.cpp \
../tests/src/platform_mock.cpp 

OBJS += \
./tests/src/catch.o \
./tests/src/gl_mock.o \
./tests/src/platform_mock.o 

CPP_DEPS += \
./tests/src/catch.d \
./tests/src/gl_mock.d \
./tests/src/platform_mock.d 


# Each subdirectory must supply rules for building sources it contributes
tests/src/%.o: ../tests/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


