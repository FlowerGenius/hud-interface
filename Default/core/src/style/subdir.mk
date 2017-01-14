################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/style/debugStyle.cpp \
../core/src/style/debugTextStyle.cpp \
../core/src/style/material.cpp \
../core/src/style/pointStyle.cpp \
../core/src/style/pointStyleBuilder.cpp \
../core/src/style/polygonStyle.cpp \
../core/src/style/polylineStyle.cpp \
../core/src/style/rasterStyle.cpp \
../core/src/style/style.cpp \
../core/src/style/textStyle.cpp \
../core/src/style/textStyleBuilder.cpp 

OBJS += \
./core/src/style/debugStyle.o \
./core/src/style/debugTextStyle.o \
./core/src/style/material.o \
./core/src/style/pointStyle.o \
./core/src/style/pointStyleBuilder.o \
./core/src/style/polygonStyle.o \
./core/src/style/polylineStyle.o \
./core/src/style/rasterStyle.o \
./core/src/style/style.o \
./core/src/style/textStyle.o \
./core/src/style/textStyleBuilder.o 

CPP_DEPS += \
./core/src/style/debugStyle.d \
./core/src/style/debugTextStyle.d \
./core/src/style/material.d \
./core/src/style/pointStyle.d \
./core/src/style/pointStyleBuilder.d \
./core/src/style/polygonStyle.d \
./core/src/style/polylineStyle.d \
./core/src/style/rasterStyle.d \
./core/src/style/style.d \
./core/src/style/textStyle.d \
./core/src/style/textStyleBuilder.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/style/%.o: ../core/src/style/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


