################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../android/tangram/src/main/cpp/jniExports.cpp \
../android/tangram/src/main/cpp/platform_android.cpp 

OBJS += \
./android/tangram/src/main/cpp/jniExports.o \
./android/tangram/src/main/cpp/platform_android.o 

CPP_DEPS += \
./android/tangram/src/main/cpp/jniExports.d \
./android/tangram/src/main/cpp/platform_android.d 


# Each subdirectory must supply rules for building sources it contributes
android/tangram/src/main/cpp/%.o: ../android/tangram/src/main/cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


