################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/benchmark/cmake/gnu_posix_regex.cpp \
../external/benchmark/cmake/posix_regex.cpp \
../external/benchmark/cmake/std_regex.cpp \
../external/benchmark/cmake/steady_clock.cpp \
../external/benchmark/cmake/thread_safety_attributes.cpp 

OBJS += \
./external/benchmark/cmake/gnu_posix_regex.o \
./external/benchmark/cmake/posix_regex.o \
./external/benchmark/cmake/std_regex.o \
./external/benchmark/cmake/steady_clock.o \
./external/benchmark/cmake/thread_safety_attributes.o 

CPP_DEPS += \
./external/benchmark/cmake/gnu_posix_regex.d \
./external/benchmark/cmake/posix_regex.d \
./external/benchmark/cmake/std_regex.d \
./external/benchmark/cmake/steady_clock.d \
./external/benchmark/cmake/thread_safety_attributes.d 


# Each subdirectory must supply rules for building sources it contributes
external/benchmark/cmake/%.o: ../external/benchmark/cmake/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


