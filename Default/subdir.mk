################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HUD2.cpp \
../HeadsUpBatteryInfo.cpp \
../HeadsUpCheckBox.cpp \
../HeadsUpDigitalClock.cpp \
../HeadsUpInterface.cpp \
../HeadsUpMap.cpp \
../HeadsUpObjective.cpp \
../HeadsUpTask.cpp \
../HeadsUpWaypoint.cpp \
../ScalableVectorString.cpp \
../helper_functions.cpp 

O_SRCS += \
../HUD2.o 

OBJS += \
./HUD2.o \
./HeadsUpBatteryInfo.o \
./HeadsUpCheckBox.o \
./HeadsUpDigitalClock.o \
./HeadsUpInterface.o \
./HeadsUpMap.o \
./HeadsUpObjective.o \
./HeadsUpTask.o \
./HeadsUpWaypoint.o \
./ScalableVectorString.o \
./helper_functions.o 

CPP_DEPS += \
./HUD2.d \
./HeadsUpBatteryInfo.d \
./HeadsUpCheckBox.d \
./HeadsUpDigitalClock.d \
./HeadsUpInterface.d \
./HeadsUpMap.d \
./HeadsUpObjective.d \
./HeadsUpTask.d \
./HeadsUpWaypoint.d \
./ScalableVectorString.d \
./helper_functions.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


