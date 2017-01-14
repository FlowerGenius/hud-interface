################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/fused-src/gmock-gtest-all.cc \
../external/yaml-cpp/test/gmock-1.7.0/fused-src/gmock_main.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/fused-src/gmock-gtest-all.d \
./external/yaml-cpp/test/gmock-1.7.0/fused-src/gmock_main.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/fused-src/gmock-gtest-all.o \
./external/yaml-cpp/test/gmock-1.7.0/fused-src/gmock_main.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/fused-src/%.o: ../external/yaml-cpp/test/gmock-1.7.0/fused-src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


