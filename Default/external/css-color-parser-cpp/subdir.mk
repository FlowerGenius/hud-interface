################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/css-color-parser-cpp/csscolorparser.cpp \
../external/css-color-parser-cpp/main.cpp 

OBJS += \
./external/css-color-parser-cpp/csscolorparser.o \
./external/css-color-parser-cpp/main.o 

CPP_DEPS += \
./external/css-color-parser-cpp/csscolorparser.d \
./external/css-color-parser-cpp/main.d 


# Each subdirectory must supply rules for building sources it contributes
external/css-color-parser-cpp/%.o: ../external/css-color-parser-cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


