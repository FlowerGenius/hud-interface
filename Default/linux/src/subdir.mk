################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../linux/src/main.cpp \
../linux/src/platform_linux.cpp \
../linux/src/urlWorker.cpp 

OBJS += \
./linux/src/main.o \
./linux/src/platform_linux.o \
./linux/src/urlWorker.o 

CPP_DEPS += \
./linux/src/main.d \
./linux/src/platform_linux.d \
./linux/src/urlWorker.d 


# Each subdirectory must supply rules for building sources it contributes
linux/src/%.o: ../linux/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


