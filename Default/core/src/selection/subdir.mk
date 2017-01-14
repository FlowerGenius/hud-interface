################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/selection/featureSelection.cpp \
../core/src/selection/selectionQuery.cpp 

OBJS += \
./core/src/selection/featureSelection.o \
./core/src/selection/selectionQuery.o 

CPP_DEPS += \
./core/src/selection/featureSelection.d \
./core/src/selection/selectionQuery.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/selection/%.o: ../core/src/selection/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


