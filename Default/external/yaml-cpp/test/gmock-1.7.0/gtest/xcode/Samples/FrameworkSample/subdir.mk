################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/widget.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/widget_test.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/widget.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/widget_test.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/widget.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/widget_test.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/%.o: ../external/yaml-cpp/test/gmock-1.7.0/gtest/xcode/Samples/FrameworkSample/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


