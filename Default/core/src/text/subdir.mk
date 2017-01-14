################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/text/fontContext.cpp \
../core/src/text/textUtil.cpp 

OBJS += \
./core/src/text/fontContext.o \
./core/src/text/textUtil.o 

CPP_DEPS += \
./core/src/text/fontContext.d \
./core/src/text/textUtil.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/text/%.o: ../core/src/text/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


