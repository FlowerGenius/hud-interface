################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/labels/label.cpp \
../core/src/labels/labelCollider.cpp \
../core/src/labels/labelProperty.cpp \
../core/src/labels/labelSet.cpp \
../core/src/labels/labels.cpp \
../core/src/labels/spriteLabel.cpp \
../core/src/labels/textLabel.cpp 

OBJS += \
./core/src/labels/label.o \
./core/src/labels/labelCollider.o \
./core/src/labels/labelProperty.o \
./core/src/labels/labelSet.o \
./core/src/labels/labels.o \
./core/src/labels/spriteLabel.o \
./core/src/labels/textLabel.o 

CPP_DEPS += \
./core/src/labels/label.d \
./core/src/labels/labelCollider.d \
./core/src/labels/labelProperty.d \
./core/src/labels/labelSet.d \
./core/src/labels/labels.d \
./core/src/labels/spriteLabel.d \
./core/src/labels/textLabel.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/labels/%.o: ../core/src/labels/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


