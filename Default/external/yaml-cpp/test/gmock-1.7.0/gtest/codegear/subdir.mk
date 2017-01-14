################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/gtest_all.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/gtest_link.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/gtest_all.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/gtest_link.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/gtest_all.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/gtest_link.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/%.o: ../external/yaml-cpp/test/gmock-1.7.0/gtest/codegear/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


