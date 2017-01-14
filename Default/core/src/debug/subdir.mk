################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/debug/frameInfo.cpp \
../core/src/debug/textDisplay.cpp 

OBJS += \
./core/src/debug/frameInfo.o \
./core/src/debug/textDisplay.o 

CPP_DEPS += \
./core/src/debug/frameInfo.d \
./core/src/debug/textDisplay.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/debug/%.o: ../core/src/debug/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


