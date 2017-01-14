################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-all.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-death-test.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-filepath.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-port.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-printers.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-test-part.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-typed-test.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest_main.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-all.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-death-test.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-filepath.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-port.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-printers.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-test-part.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-typed-test.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest_main.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-all.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-death-test.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-filepath.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-port.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-printers.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-test-part.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest-typed-test.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/src/gtest_main.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/gtest/src/%.o: ../external/yaml-cpp/test/gmock-1.7.0/gtest/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


