################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/yaml-cpp/test/node/node_test.cpp 

OBJS += \
./external/yaml-cpp/test/node/node_test.o 

CPP_DEPS += \
./external/yaml-cpp/test/node/node_test.d 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/node/%.o: ../external/yaml-cpp/test/node/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


