################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/yaml-cpp/util/api.cpp \
../external/yaml-cpp/util/parse.cpp \
../external/yaml-cpp/util/read.cpp \
../external/yaml-cpp/util/sandbox.cpp 

OBJS += \
./external/yaml-cpp/util/api.o \
./external/yaml-cpp/util/parse.o \
./external/yaml-cpp/util/read.o \
./external/yaml-cpp/util/sandbox.o 

CPP_DEPS += \
./external/yaml-cpp/util/api.d \
./external/yaml-cpp/util/parse.d \
./external/yaml-cpp/util/read.d \
./external/yaml-cpp/util/sandbox.d 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/util/%.o: ../external/yaml-cpp/util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


