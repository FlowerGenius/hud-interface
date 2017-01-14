################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/unit/curlTests.cpp \
../tests/unit/drawRuleTests.cpp \
../tests/unit/dukTests.cpp \
../tests/unit/fileTests.cpp \
../tests/unit/labelTests.cpp \
../tests/unit/labelsTests.cpp \
../tests/unit/layerTests.cpp \
../tests/unit/lineWrapTests.cpp \
../tests/unit/mercProjTests.cpp \
../tests/unit/meshTests.cpp \
../tests/unit/sceneImportTests.cpp \
../tests/unit/sceneLoaderTests.cpp \
../tests/unit/sceneUpdateTests.cpp \
../tests/unit/stopsTests.cpp \
../tests/unit/styleMixerTests.cpp \
../tests/unit/styleSortingTests.cpp \
../tests/unit/styleUniformsTests.cpp \
../tests/unit/textureTests.cpp \
../tests/unit/tileIDTests.cpp \
../tests/unit/tileManagerTests.cpp \
../tests/unit/urlTests.cpp \
../tests/unit/yamlFilterTests.cpp 

OBJS += \
./tests/unit/curlTests.o \
./tests/unit/drawRuleTests.o \
./tests/unit/dukTests.o \
./tests/unit/fileTests.o \
./tests/unit/labelTests.o \
./tests/unit/labelsTests.o \
./tests/unit/layerTests.o \
./tests/unit/lineWrapTests.o \
./tests/unit/mercProjTests.o \
./tests/unit/meshTests.o \
./tests/unit/sceneImportTests.o \
./tests/unit/sceneLoaderTests.o \
./tests/unit/sceneUpdateTests.o \
./tests/unit/stopsTests.o \
./tests/unit/styleMixerTests.o \
./tests/unit/styleSortingTests.o \
./tests/unit/styleUniformsTests.o \
./tests/unit/textureTests.o \
./tests/unit/tileIDTests.o \
./tests/unit/tileManagerTests.o \
./tests/unit/urlTests.o \
./tests/unit/yamlFilterTests.o 

CPP_DEPS += \
./tests/unit/curlTests.d \
./tests/unit/drawRuleTests.d \
./tests/unit/dukTests.d \
./tests/unit/fileTests.d \
./tests/unit/labelTests.d \
./tests/unit/labelsTests.d \
./tests/unit/layerTests.d \
./tests/unit/lineWrapTests.d \
./tests/unit/mercProjTests.d \
./tests/unit/meshTests.d \
./tests/unit/sceneImportTests.d \
./tests/unit/sceneLoaderTests.d \
./tests/unit/sceneUpdateTests.d \
./tests/unit/stopsTests.d \
./tests/unit/styleMixerTests.d \
./tests/unit/styleSortingTests.d \
./tests/unit/styleUniformsTests.d \
./tests/unit/textureTests.d \
./tests/unit/tileIDTests.d \
./tests/unit/tileManagerTests.d \
./tests/unit/urlTests.d \
./tests/unit/yamlFilterTests.d 


# Each subdirectory must supply rules for building sources it contributes
tests/unit/%.o: ../tests/unit/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


