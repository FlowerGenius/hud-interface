################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/geojson-vt-cpp/debug/debug.cpp 

OBJS += \
./external/geojson-vt-cpp/debug/debug.o 

CPP_DEPS += \
./external/geojson-vt-cpp/debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
external/geojson-vt-cpp/debug/%.o: ../external/geojson-vt-cpp/debug/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


