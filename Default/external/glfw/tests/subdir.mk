################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/glfw/tests/clipboard.c \
../external/glfw/tests/cursor.c \
../external/glfw/tests/empty.c \
../external/glfw/tests/events.c \
../external/glfw/tests/gamma.c \
../external/glfw/tests/glfwinfo.c \
../external/glfw/tests/iconify.c \
../external/glfw/tests/joysticks.c \
../external/glfw/tests/monitors.c \
../external/glfw/tests/msaa.c \
../external/glfw/tests/reopen.c \
../external/glfw/tests/sharing.c \
../external/glfw/tests/tearing.c \
../external/glfw/tests/threads.c \
../external/glfw/tests/title.c \
../external/glfw/tests/windows.c 

OBJS += \
./external/glfw/tests/clipboard.o \
./external/glfw/tests/cursor.o \
./external/glfw/tests/empty.o \
./external/glfw/tests/events.o \
./external/glfw/tests/gamma.o \
./external/glfw/tests/glfwinfo.o \
./external/glfw/tests/iconify.o \
./external/glfw/tests/joysticks.o \
./external/glfw/tests/monitors.o \
./external/glfw/tests/msaa.o \
./external/glfw/tests/reopen.o \
./external/glfw/tests/sharing.o \
./external/glfw/tests/tearing.o \
./external/glfw/tests/threads.o \
./external/glfw/tests/title.o \
./external/glfw/tests/windows.o 

C_DEPS += \
./external/glfw/tests/clipboard.d \
./external/glfw/tests/cursor.d \
./external/glfw/tests/empty.d \
./external/glfw/tests/events.d \
./external/glfw/tests/gamma.d \
./external/glfw/tests/glfwinfo.d \
./external/glfw/tests/iconify.d \
./external/glfw/tests/joysticks.d \
./external/glfw/tests/monitors.d \
./external/glfw/tests/msaa.d \
./external/glfw/tests/reopen.d \
./external/glfw/tests/sharing.d \
./external/glfw/tests/tearing.d \
./external/glfw/tests/threads.d \
./external/glfw/tests/title.d \
./external/glfw/tests/windows.d 


# Each subdirectory must supply rules for building sources it contributes
external/glfw/tests/%.o: ../external/glfw/tests/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


