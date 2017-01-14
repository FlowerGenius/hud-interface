################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/gl/disposer.cpp \
../core/src/gl/error.cpp \
../core/src/gl/framebuffer.cpp \
../core/src/gl/hardware.cpp \
../core/src/gl/mesh.cpp \
../core/src/gl/primitives.cpp \
../core/src/gl/renderState.cpp \
../core/src/gl/shaderProgram.cpp \
../core/src/gl/texture.cpp \
../core/src/gl/textureCube.cpp \
../core/src/gl/vao.cpp \
../core/src/gl/vertexLayout.cpp 

OBJS += \
./core/src/gl/disposer.o \
./core/src/gl/error.o \
./core/src/gl/framebuffer.o \
./core/src/gl/hardware.o \
./core/src/gl/mesh.o \
./core/src/gl/primitives.o \
./core/src/gl/renderState.o \
./core/src/gl/shaderProgram.o \
./core/src/gl/texture.o \
./core/src/gl/textureCube.o \
./core/src/gl/vao.o \
./core/src/gl/vertexLayout.o 

CPP_DEPS += \
./core/src/gl/disposer.d \
./core/src/gl/error.d \
./core/src/gl/framebuffer.d \
./core/src/gl/hardware.d \
./core/src/gl/mesh.d \
./core/src/gl/primitives.d \
./core/src/gl/renderState.d \
./core/src/gl/shaderProgram.d \
./core/src/gl/texture.d \
./core/src/gl/textureCube.d \
./core/src/gl/vao.d \
./core/src/gl/vertexLayout.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/gl/%.o: ../core/src/gl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


