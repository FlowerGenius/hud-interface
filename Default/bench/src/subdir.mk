################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bench/src/builders.cpp \
../bench/src/tileLoading.cpp 

OBJS += \
./bench/src/builders.o \
./bench/src/tileLoading.o 

CPP_DEPS += \
./bench/src/builders.d \
./bench/src/tileLoading.d 


# Each subdirectory must supply rules for building sources it contributes
bench/src/%.o: ../bench/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


