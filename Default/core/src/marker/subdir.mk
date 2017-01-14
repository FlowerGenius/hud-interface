################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/marker/marker.cpp \
../core/src/marker/markerManager.cpp 

OBJS += \
./core/src/marker/marker.o \
./core/src/marker/markerManager.o 

CPP_DEPS += \
./core/src/marker/marker.d \
./core/src/marker/markerManager.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/marker/%.o: ../core/src/marker/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


