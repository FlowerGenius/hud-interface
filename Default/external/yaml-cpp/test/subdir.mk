################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/yaml-cpp/test/main.cpp \
../external/yaml-cpp/test/ostream_wrapper_test.cpp \
../external/yaml-cpp/test/regex_test.cpp 

OBJS += \
./external/yaml-cpp/test/main.o \
./external/yaml-cpp/test/ostream_wrapper_test.o \
./external/yaml-cpp/test/regex_test.o 

CPP_DEPS += \
./external/yaml-cpp/test/main.d \
./external/yaml-cpp/test/ostream_wrapper_test.d \
./external/yaml-cpp/test/regex_test.d 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/%.o: ../external/yaml-cpp/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


