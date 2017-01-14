################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/view/view.cpp \
../core/src/view/viewConstraint.cpp 

OBJS += \
./core/src/view/view.o \
./core/src/view/viewConstraint.o 

CPP_DEPS += \
./core/src/view/view.d \
./core/src/view/viewConstraint.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/view/%.o: ../core/src/view/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


