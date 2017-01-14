################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../core/include/earcut.hpp/glfw/tests/clipboard.c \
../core/include/earcut.hpp/glfw/tests/cursor.c \
../core/include/earcut.hpp/glfw/tests/empty.c \
../core/include/earcut.hpp/glfw/tests/events.c \
../core/include/earcut.hpp/glfw/tests/gamma.c \
../core/include/earcut.hpp/glfw/tests/glfwinfo.c \
../core/include/earcut.hpp/glfw/tests/iconify.c \
../core/include/earcut.hpp/glfw/tests/joysticks.c \
../core/include/earcut.hpp/glfw/tests/monitors.c \
../core/include/earcut.hpp/glfw/tests/msaa.c \
../core/include/earcut.hpp/glfw/tests/reopen.c \
../core/include/earcut.hpp/glfw/tests/sharing.c \
../core/include/earcut.hpp/glfw/tests/tearing.c \
../core/include/earcut.hpp/glfw/tests/threads.c \
../core/include/earcut.hpp/glfw/tests/title.c \
../core/include/earcut.hpp/glfw/tests/vulkan.c \
../core/include/earcut.hpp/glfw/tests/windows.c 

OBJS += \
./core/include/earcut.hpp/glfw/tests/clipboard.o \
./core/include/earcut.hpp/glfw/tests/cursor.o \
./core/include/earcut.hpp/glfw/tests/empty.o \
./core/include/earcut.hpp/glfw/tests/events.o \
./core/include/earcut.hpp/glfw/tests/gamma.o \
./core/include/earcut.hpp/glfw/tests/glfwinfo.o \
./core/include/earcut.hpp/glfw/tests/iconify.o \
./core/include/earcut.hpp/glfw/tests/joysticks.o \
./core/include/earcut.hpp/glfw/tests/monitors.o \
./core/include/earcut.hpp/glfw/tests/msaa.o \
./core/include/earcut.hpp/glfw/tests/reopen.o \
./core/include/earcut.hpp/glfw/tests/sharing.o \
./core/include/earcut.hpp/glfw/tests/tearing.o \
./core/include/earcut.hpp/glfw/tests/threads.o \
./core/include/earcut.hpp/glfw/tests/title.o \
./core/include/earcut.hpp/glfw/tests/vulkan.o \
./core/include/earcut.hpp/glfw/tests/windows.o 

C_DEPS += \
./core/include/earcut.hpp/glfw/tests/clipboard.d \
./core/include/earcut.hpp/glfw/tests/cursor.d \
./core/include/earcut.hpp/glfw/tests/empty.d \
./core/include/earcut.hpp/glfw/tests/events.d \
./core/include/earcut.hpp/glfw/tests/gamma.d \
./core/include/earcut.hpp/glfw/tests/glfwinfo.d \
./core/include/earcut.hpp/glfw/tests/iconify.d \
./core/include/earcut.hpp/glfw/tests/joysticks.d \
./core/include/earcut.hpp/glfw/tests/monitors.d \
./core/include/earcut.hpp/glfw/tests/msaa.d \
./core/include/earcut.hpp/glfw/tests/reopen.d \
./core/include/earcut.hpp/glfw/tests/sharing.d \
./core/include/earcut.hpp/glfw/tests/tearing.d \
./core/include/earcut.hpp/glfw/tests/threads.d \
./core/include/earcut.hpp/glfw/tests/title.d \
./core/include/earcut.hpp/glfw/tests/vulkan.d \
./core/include/earcut.hpp/glfw/tests/windows.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/earcut.hpp/glfw/tests/%.o: ../core/include/earcut.hpp/glfw/tests/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


