################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../core/include/earcut.hpp/glfw/deps/getopt.c \
../core/include/earcut.hpp/glfw/deps/glad.c \
../core/include/earcut.hpp/glfw/deps/tinycthread.c 

OBJS += \
./core/include/earcut.hpp/glfw/deps/getopt.o \
./core/include/earcut.hpp/glfw/deps/glad.o \
./core/include/earcut.hpp/glfw/deps/tinycthread.o 

C_DEPS += \
./core/include/earcut.hpp/glfw/deps/getopt.d \
./core/include/earcut.hpp/glfw/deps/glad.d \
./core/include/earcut.hpp/glfw/deps/tinycthread.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/earcut.hpp/glfw/deps/%.o: ../core/include/earcut.hpp/glfw/deps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


