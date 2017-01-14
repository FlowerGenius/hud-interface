################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/yaml-cpp/src/contrib/graphbuilder.cpp \
../external/yaml-cpp/src/contrib/graphbuilderadapter.cpp 

OBJS += \
./external/yaml-cpp/src/contrib/graphbuilder.o \
./external/yaml-cpp/src/contrib/graphbuilderadapter.o 

CPP_DEPS += \
./external/yaml-cpp/src/contrib/graphbuilder.d \
./external/yaml-cpp/src/contrib/graphbuilderadapter.d 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/src/contrib/%.o: ../external/yaml-cpp/src/contrib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


