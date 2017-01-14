################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/earcut.hpp/test/bench.cpp \
../core/include/earcut.hpp/test/tap.cpp \
../core/include/earcut.hpp/test/test.cpp \
../core/include/earcut.hpp/test/viz.cpp 

OBJS += \
./core/include/earcut.hpp/test/bench.o \
./core/include/earcut.hpp/test/tap.o \
./core/include/earcut.hpp/test/test.o \
./core/include/earcut.hpp/test/viz.o 

CPP_DEPS += \
./core/include/earcut.hpp/test/bench.d \
./core/include/earcut.hpp/test/tap.d \
./core/include/earcut.hpp/test/test.d \
./core/include/earcut.hpp/test/viz.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/earcut.hpp/test/%.o: ../core/include/earcut.hpp/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


