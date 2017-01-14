################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/benchmark/test/basic_test.cc \
../external/benchmark/test/benchmark_test.cc \
../external/benchmark/test/cxx03_test.cc \
../external/benchmark/test/filter_test.cc \
../external/benchmark/test/fixture_test.cc \
../external/benchmark/test/options_test.cc 

CC_DEPS += \
./external/benchmark/test/basic_test.d \
./external/benchmark/test/benchmark_test.d \
./external/benchmark/test/cxx03_test.d \
./external/benchmark/test/filter_test.d \
./external/benchmark/test/fixture_test.d \
./external/benchmark/test/options_test.d 

OBJS += \
./external/benchmark/test/basic_test.o \
./external/benchmark/test/benchmark_test.o \
./external/benchmark/test/cxx03_test.o \
./external/benchmark/test/filter_test.o \
./external/benchmark/test/fixture_test.o \
./external/benchmark/test/options_test.o 


# Each subdirectory must supply rules for building sources it contributes
external/benchmark/test/%.o: ../external/benchmark/test/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


