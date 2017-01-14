################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/alfons/src/alfons/path/lineSampler.cpp \
../external/alfons/src/alfons/path/splinePath.cpp 

OBJS += \
./external/alfons/src/alfons/path/lineSampler.o \
./external/alfons/src/alfons/path/splinePath.o 

CPP_DEPS += \
./external/alfons/src/alfons/path/lineSampler.d \
./external/alfons/src/alfons/path/splinePath.d 


# Each subdirectory must supply rules for building sources it contributes
external/alfons/src/alfons/path/%.o: ../external/alfons/src/alfons/path/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


