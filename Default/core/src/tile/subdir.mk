################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/tile/tile.cpp \
../core/src/tile/tileBuilder.cpp \
../core/src/tile/tileManager.cpp \
../core/src/tile/tileTask.cpp \
../core/src/tile/tileWorker.cpp 

OBJS += \
./core/src/tile/tile.o \
./core/src/tile/tileBuilder.o \
./core/src/tile/tileManager.o \
./core/src/tile/tileTask.o \
./core/src/tile/tileWorker.o 

CPP_DEPS += \
./core/src/tile/tile.d \
./core/src/tile/tileBuilder.d \
./core/src/tile/tileManager.d \
./core/src/tile/tileTask.d \
./core/src/tile/tileWorker.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/tile/%.o: ../core/src/tile/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


