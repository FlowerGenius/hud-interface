################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/isect2d/tests/main.cpp 

OBJS += \
./core/include/isect2d/tests/main.o 

CPP_DEPS += \
./core/include/isect2d/tests/main.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/isect2d/tests/%.o: ../core/include/isect2d/tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


