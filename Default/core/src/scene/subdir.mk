################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/scene/ambientLight.cpp \
../core/src/scene/dataLayer.cpp \
../core/src/scene/directionalLight.cpp \
../core/src/scene/drawRule.cpp \
../core/src/scene/filters.cpp \
../core/src/scene/importer.cpp \
../core/src/scene/light.cpp \
../core/src/scene/pointLight.cpp \
../core/src/scene/scene.cpp \
../core/src/scene/sceneLayer.cpp \
../core/src/scene/sceneLoader.cpp \
../core/src/scene/skybox.cpp \
../core/src/scene/spotLight.cpp \
../core/src/scene/spriteAtlas.cpp \
../core/src/scene/stops.cpp \
../core/src/scene/styleContext.cpp \
../core/src/scene/styleMixer.cpp \
../core/src/scene/styleParam.cpp 

OBJS += \
./core/src/scene/ambientLight.o \
./core/src/scene/dataLayer.o \
./core/src/scene/directionalLight.o \
./core/src/scene/drawRule.o \
./core/src/scene/filters.o \
./core/src/scene/importer.o \
./core/src/scene/light.o \
./core/src/scene/pointLight.o \
./core/src/scene/scene.o \
./core/src/scene/sceneLayer.o \
./core/src/scene/sceneLoader.o \
./core/src/scene/skybox.o \
./core/src/scene/spotLight.o \
./core/src/scene/spriteAtlas.o \
./core/src/scene/stops.o \
./core/src/scene/styleContext.o \
./core/src/scene/styleMixer.o \
./core/src/scene/styleParam.o 

CPP_DEPS += \
./core/src/scene/ambientLight.d \
./core/src/scene/dataLayer.d \
./core/src/scene/directionalLight.d \
./core/src/scene/drawRule.d \
./core/src/scene/filters.d \
./core/src/scene/importer.d \
./core/src/scene/light.d \
./core/src/scene/pointLight.d \
./core/src/scene/scene.d \
./core/src/scene/sceneLayer.d \
./core/src/scene/sceneLoader.d \
./core/src/scene/skybox.d \
./core/src/scene/spotLight.d \
./core/src/scene/spriteAtlas.d \
./core/src/scene/stops.d \
./core/src/scene/styleContext.d \
./core/src/scene/styleMixer.d \
./core/src/scene/styleParam.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/scene/%.o: ../core/src/scene/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


