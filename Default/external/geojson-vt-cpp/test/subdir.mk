################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/geojson-vt-cpp/test/test.cpp \
../external/geojson-vt-cpp/test/test_clip.cpp \
../external/geojson-vt-cpp/test/test_full.cpp \
../external/geojson-vt-cpp/test/test_get_tile.cpp \
../external/geojson-vt-cpp/test/test_simplify.cpp \
../external/geojson-vt-cpp/test/util.cpp 

OBJS += \
./external/geojson-vt-cpp/test/test.o \
./external/geojson-vt-cpp/test/test_clip.o \
./external/geojson-vt-cpp/test/test_full.o \
./external/geojson-vt-cpp/test/test_get_tile.o \
./external/geojson-vt-cpp/test/test_simplify.o \
./external/geojson-vt-cpp/test/util.o 

CPP_DEPS += \
./external/geojson-vt-cpp/test/test.d \
./external/geojson-vt-cpp/test/test_clip.d \
./external/geojson-vt-cpp/test/test_full.d \
./external/geojson-vt-cpp/test/test_get_tile.d \
./external/geojson-vt-cpp/test/test_simplify.d \
./external/geojson-vt-cpp/test/util.d 


# Each subdirectory must supply rules for building sources it contributes
external/geojson-vt-cpp/test/%.o: ../external/geojson-vt-cpp/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


