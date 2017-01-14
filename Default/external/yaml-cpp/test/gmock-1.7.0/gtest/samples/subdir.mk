################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample1.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample10_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample1_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample2.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample2_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample3_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample4.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample4_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample5_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample6_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample7_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample8_unittest.cc \
../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample9_unittest.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample1.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample10_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample1_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample2.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample2_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample3_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample4.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample4_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample5_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample6_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample7_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample8_unittest.d \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample9_unittest.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample1.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample10_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample1_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample2.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample2_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample3_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample4.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample4_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample5_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample6_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample7_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample8_unittest.o \
./external/yaml-cpp/test/gmock-1.7.0/gtest/samples/sample9_unittest.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/gtest/samples/%.o: ../external/yaml-cpp/test/gmock-1.7.0/gtest/samples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


