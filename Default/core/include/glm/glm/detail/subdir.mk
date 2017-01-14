################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/glm/glm/detail/dummy.cpp \
../core/include/glm/glm/detail/glm.cpp 

OBJS += \
./core/include/glm/glm/detail/dummy.o \
./core/include/glm/glm/detail/glm.o 

CPP_DEPS += \
./core/include/glm/glm/detail/dummy.d \
./core/include/glm/glm/detail/glm.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/glm/glm/detail/%.o: ../core/include/glm/glm/detail/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


