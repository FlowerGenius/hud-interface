################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/glm/test/external/gli/core/dummy.cpp 

OBJS += \
./core/include/glm/test/external/gli/core/dummy.o 

CPP_DEPS += \
./core/include/glm/test/external/gli/core/dummy.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/glm/test/external/gli/core/%.o: ../core/include/glm/test/external/gli/core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


