################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/glfw/deps/getopt.c \
../external/glfw/deps/glad.c \
../external/glfw/deps/tinycthread.c 

OBJS += \
./external/glfw/deps/getopt.o \
./external/glfw/deps/glad.o \
./external/glfw/deps/tinycthread.o 

C_DEPS += \
./external/glfw/deps/getopt.d \
./external/glfw/deps/glad.d \
./external/glfw/deps/tinycthread.d 


# Each subdirectory must supply rules for building sources it contributes
external/glfw/deps/%.o: ../external/glfw/deps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


