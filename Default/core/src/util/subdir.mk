################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/util/builders.cpp \
../core/src/util/dashArray.cpp \
../core/src/util/extrude.cpp \
../core/src/util/geoJson.cpp \
../core/src/util/geom.cpp \
../core/src/util/inputHandler.cpp \
../core/src/util/jobQueue.cpp \
../core/src/util/json.cpp \
../core/src/util/mapProjection.cpp \
../core/src/util/pbfParser.cpp \
../core/src/util/rasterize.cpp \
../core/src/util/topoJson.cpp \
../core/src/util/url.cpp \
../core/src/util/yamlHelper.cpp 

OBJS += \
./core/src/util/builders.o \
./core/src/util/dashArray.o \
./core/src/util/extrude.o \
./core/src/util/geoJson.o \
./core/src/util/geom.o \
./core/src/util/inputHandler.o \
./core/src/util/jobQueue.o \
./core/src/util/json.o \
./core/src/util/mapProjection.o \
./core/src/util/pbfParser.o \
./core/src/util/rasterize.o \
./core/src/util/topoJson.o \
./core/src/util/url.o \
./core/src/util/yamlHelper.o 

CPP_DEPS += \
./core/src/util/builders.d \
./core/src/util/dashArray.d \
./core/src/util/extrude.d \
./core/src/util/geoJson.d \
./core/src/util/geom.d \
./core/src/util/inputHandler.d \
./core/src/util/jobQueue.d \
./core/src/util/json.d \
./core/src/util/mapProjection.d \
./core/src/util/pbfParser.d \
./core/src/util/rasterize.d \
./core/src/util/topoJson.d \
./core/src/util/url.d \
./core/src/util/yamlHelper.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/util/%.o: ../core/src/util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


