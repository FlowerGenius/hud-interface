################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/src/data/clientGeoJsonSource.cpp \
../core/src/data/geoJsonSource.cpp \
../core/src/data/memoryCacheDataSource.cpp \
../core/src/data/mvtSource.cpp \
../core/src/data/networkDataSource.cpp \
../core/src/data/properties.cpp \
../core/src/data/rasterSource.cpp \
../core/src/data/tileSource.cpp \
../core/src/data/topoJsonSource.cpp 

OBJS += \
./core/src/data/clientGeoJsonSource.o \
./core/src/data/geoJsonSource.o \
./core/src/data/memoryCacheDataSource.o \
./core/src/data/mvtSource.o \
./core/src/data/networkDataSource.o \
./core/src/data/properties.o \
./core/src/data/rasterSource.o \
./core/src/data/tileSource.o \
./core/src/data/topoJsonSource.o 

CPP_DEPS += \
./core/src/data/clientGeoJsonSource.d \
./core/src/data/geoJsonSource.d \
./core/src/data/memoryCacheDataSource.d \
./core/src/data/mvtSource.d \
./core/src/data/networkDataSource.d \
./core/src/data/properties.d \
./core/src/data/rasterSource.d \
./core/src/data/tileSource.d \
./core/src/data/topoJsonSource.d 


# Each subdirectory must supply rules for building sources it contributes
core/src/data/%.o: ../core/src/data/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


