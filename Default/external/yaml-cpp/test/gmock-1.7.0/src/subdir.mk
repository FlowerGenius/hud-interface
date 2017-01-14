################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock-all.cc \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock-cardinalities.cc \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock-internal-utils.cc \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock-matchers.cc \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock-spec-builders.cc \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock.cc \
../external/yaml-cpp/test/gmock-1.7.0/src/gmock_main.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-all.d \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-cardinalities.d \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-internal-utils.d \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-matchers.d \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-spec-builders.d \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock.d \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock_main.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-all.o \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-cardinalities.o \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-internal-utils.o \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-matchers.o \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock-spec-builders.o \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock.o \
./external/yaml-cpp/test/gmock-1.7.0/src/gmock_main.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/src/%.o: ../external/yaml-cpp/test/gmock-1.7.0/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


