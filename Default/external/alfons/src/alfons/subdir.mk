################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/alfons/src/alfons/alfons.cpp \
../external/alfons/src/alfons/atlas.cpp \
../external/alfons/src/alfons/font.cpp \
../external/alfons/src/alfons/fontFace.cpp \
../external/alfons/src/alfons/fontManager.cpp \
../external/alfons/src/alfons/langHelper.cpp \
../external/alfons/src/alfons/quadMatrix.cpp \
../external/alfons/src/alfons/scrptrun.cpp \
../external/alfons/src/alfons/textBatch.cpp \
../external/alfons/src/alfons/textShaper.cpp 

OBJS += \
./external/alfons/src/alfons/alfons.o \
./external/alfons/src/alfons/atlas.o \
./external/alfons/src/alfons/font.o \
./external/alfons/src/alfons/fontFace.o \
./external/alfons/src/alfons/fontManager.o \
./external/alfons/src/alfons/langHelper.o \
./external/alfons/src/alfons/quadMatrix.o \
./external/alfons/src/alfons/scrptrun.o \
./external/alfons/src/alfons/textBatch.o \
./external/alfons/src/alfons/textShaper.o 

CPP_DEPS += \
./external/alfons/src/alfons/alfons.d \
./external/alfons/src/alfons/atlas.d \
./external/alfons/src/alfons/font.d \
./external/alfons/src/alfons/fontFace.d \
./external/alfons/src/alfons/fontManager.d \
./external/alfons/src/alfons/langHelper.d \
./external/alfons/src/alfons/quadMatrix.d \
./external/alfons/src/alfons/scrptrun.d \
./external/alfons/src/alfons/textBatch.d \
./external/alfons/src/alfons/textShaper.d 


# Each subdirectory must supply rules for building sources it contributes
external/alfons/src/alfons/%.o: ../external/alfons/src/alfons/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


