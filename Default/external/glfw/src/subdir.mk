################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/glfw/src/context.c \
../external/glfw/src/egl_context.c \
../external/glfw/src/glx_context.c \
../external/glfw/src/init.c \
../external/glfw/src/input.c \
../external/glfw/src/linux_joystick.c \
../external/glfw/src/mach_time.c \
../external/glfw/src/mir_init.c \
../external/glfw/src/mir_monitor.c \
../external/glfw/src/mir_window.c \
../external/glfw/src/monitor.c \
../external/glfw/src/posix_time.c \
../external/glfw/src/posix_tls.c \
../external/glfw/src/wgl_context.c \
../external/glfw/src/win32_init.c \
../external/glfw/src/win32_monitor.c \
../external/glfw/src/win32_time.c \
../external/glfw/src/win32_tls.c \
../external/glfw/src/win32_window.c \
../external/glfw/src/window.c \
../external/glfw/src/winmm_joystick.c \
../external/glfw/src/wl_init.c \
../external/glfw/src/wl_monitor.c \
../external/glfw/src/wl_window.c \
../external/glfw/src/x11_init.c \
../external/glfw/src/x11_monitor.c \
../external/glfw/src/x11_window.c \
../external/glfw/src/xkb_unicode.c 

OBJS += \
./external/glfw/src/context.o \
./external/glfw/src/egl_context.o \
./external/glfw/src/glx_context.o \
./external/glfw/src/init.o \
./external/glfw/src/input.o \
./external/glfw/src/linux_joystick.o \
./external/glfw/src/mach_time.o \
./external/glfw/src/mir_init.o \
./external/glfw/src/mir_monitor.o \
./external/glfw/src/mir_window.o \
./external/glfw/src/monitor.o \
./external/glfw/src/posix_time.o \
./external/glfw/src/posix_tls.o \
./external/glfw/src/wgl_context.o \
./external/glfw/src/win32_init.o \
./external/glfw/src/win32_monitor.o \
./external/glfw/src/win32_time.o \
./external/glfw/src/win32_tls.o \
./external/glfw/src/win32_window.o \
./external/glfw/src/window.o \
./external/glfw/src/winmm_joystick.o \
./external/glfw/src/wl_init.o \
./external/glfw/src/wl_monitor.o \
./external/glfw/src/wl_window.o \
./external/glfw/src/x11_init.o \
./external/glfw/src/x11_monitor.o \
./external/glfw/src/x11_window.o \
./external/glfw/src/xkb_unicode.o 

C_DEPS += \
./external/glfw/src/context.d \
./external/glfw/src/egl_context.d \
./external/glfw/src/glx_context.d \
./external/glfw/src/init.d \
./external/glfw/src/input.d \
./external/glfw/src/linux_joystick.d \
./external/glfw/src/mach_time.d \
./external/glfw/src/mir_init.d \
./external/glfw/src/mir_monitor.d \
./external/glfw/src/mir_window.d \
./external/glfw/src/monitor.d \
./external/glfw/src/posix_time.d \
./external/glfw/src/posix_tls.d \
./external/glfw/src/wgl_context.d \
./external/glfw/src/win32_init.d \
./external/glfw/src/win32_monitor.d \
./external/glfw/src/win32_time.d \
./external/glfw/src/win32_tls.d \
./external/glfw/src/win32_window.d \
./external/glfw/src/window.d \
./external/glfw/src/winmm_joystick.d \
./external/glfw/src/wl_init.d \
./external/glfw/src/wl_monitor.d \
./external/glfw/src/wl_window.d \
./external/glfw/src/x11_init.d \
./external/glfw/src/x11_monitor.d \
./external/glfw/src/x11_window.d \
./external/glfw/src/xkb_unicode.d 


# Each subdirectory must supply rules for building sources it contributes
external/glfw/src/%.o: ../external/glfw/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


