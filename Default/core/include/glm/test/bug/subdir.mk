################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/glm/test/bug/bug_ms_vec_static.cpp 

OBJS += \
./core/include/glm/test/bug/bug_ms_vec_static.o 

CPP_DEPS += \
./core/include/glm/test/bug/bug_ms_vec_static.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/glm/test/bug/%.o: ../core/include/glm/test/bug/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


