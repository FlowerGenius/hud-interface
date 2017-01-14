################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/glfw/examples/boing.c \
../external/glfw/examples/gears.c \
../external/glfw/examples/heightmap.c \
../external/glfw/examples/particles.c \
../external/glfw/examples/simple.c \
../external/glfw/examples/splitview.c \
../external/glfw/examples/wave.c 

OBJS += \
./external/glfw/examples/boing.o \
./external/glfw/examples/gears.o \
./external/glfw/examples/heightmap.o \
./external/glfw/examples/particles.o \
./external/glfw/examples/simple.o \
./external/glfw/examples/splitview.o \
./external/glfw/examples/wave.o 

C_DEPS += \
./external/glfw/examples/boing.d \
./external/glfw/examples/gears.d \
./external/glfw/examples/heightmap.d \
./external/glfw/examples/particles.d \
./external/glfw/examples/simple.d \
./external/glfw/examples/splitview.d \
./external/glfw/examples/wave.d 


# Each subdirectory must supply rules for building sources it contributes
external/glfw/examples/%.o: ../external/glfw/examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


