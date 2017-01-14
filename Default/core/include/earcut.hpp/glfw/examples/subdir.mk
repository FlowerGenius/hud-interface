################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../core/include/earcut.hpp/glfw/examples/boing.c \
../core/include/earcut.hpp/glfw/examples/gears.c \
../core/include/earcut.hpp/glfw/examples/heightmap.c \
../core/include/earcut.hpp/glfw/examples/particles.c \
../core/include/earcut.hpp/glfw/examples/simple.c \
../core/include/earcut.hpp/glfw/examples/splitview.c \
../core/include/earcut.hpp/glfw/examples/wave.c 

OBJS += \
./core/include/earcut.hpp/glfw/examples/boing.o \
./core/include/earcut.hpp/glfw/examples/gears.o \
./core/include/earcut.hpp/glfw/examples/heightmap.o \
./core/include/earcut.hpp/glfw/examples/particles.o \
./core/include/earcut.hpp/glfw/examples/simple.o \
./core/include/earcut.hpp/glfw/examples/splitview.o \
./core/include/earcut.hpp/glfw/examples/wave.o 

C_DEPS += \
./core/include/earcut.hpp/glfw/examples/boing.d \
./core/include/earcut.hpp/glfw/examples/gears.d \
./core/include/earcut.hpp/glfw/examples/heightmap.d \
./core/include/earcut.hpp/glfw/examples/particles.d \
./core/include/earcut.hpp/glfw/examples/simple.d \
./core/include/earcut.hpp/glfw/examples/splitview.d \
./core/include/earcut.hpp/glfw/examples/wave.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/earcut.hpp/glfw/examples/%.o: ../core/include/earcut.hpp/glfw/examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


