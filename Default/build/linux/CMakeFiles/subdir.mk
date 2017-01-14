################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../build/linux/CMakeFiles/feature_tests.cxx 

C_SRCS += \
../build/linux/CMakeFiles/feature_tests.c 

CXX_DEPS += \
./build/linux/CMakeFiles/feature_tests.d 

OBJS += \
./build/linux/CMakeFiles/feature_tests.o 

C_DEPS += \
./build/linux/CMakeFiles/feature_tests.d 


# Each subdirectory must supply rules for building sources it contributes
build/linux/CMakeFiles/%.o: ../build/linux/CMakeFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

build/linux/CMakeFiles/%.o: ../build/linux/CMakeFiles/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


