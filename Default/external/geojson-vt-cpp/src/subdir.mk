################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/geojson-vt-cpp/src/geojsonvt.cpp \
../external/geojson-vt-cpp/src/geojsonvt_clip.cpp \
../external/geojson-vt-cpp/src/geojsonvt_convert.cpp \
../external/geojson-vt-cpp/src/geojsonvt_simplify.cpp \
../external/geojson-vt-cpp/src/geojsonvt_tile.cpp \
../external/geojson-vt-cpp/src/geojsonvt_wrap.cpp 

OBJS += \
./external/geojson-vt-cpp/src/geojsonvt.o \
./external/geojson-vt-cpp/src/geojsonvt_clip.o \
./external/geojson-vt-cpp/src/geojsonvt_convert.o \
./external/geojson-vt-cpp/src/geojsonvt_simplify.o \
./external/geojson-vt-cpp/src/geojsonvt_tile.o \
./external/geojson-vt-cpp/src/geojsonvt_wrap.o 

CPP_DEPS += \
./external/geojson-vt-cpp/src/geojsonvt.d \
./external/geojson-vt-cpp/src/geojsonvt_clip.d \
./external/geojson-vt-cpp/src/geojsonvt_convert.d \
./external/geojson-vt-cpp/src/geojsonvt_simplify.d \
./external/geojson-vt-cpp/src/geojsonvt_tile.d \
./external/geojson-vt-cpp/src/geojsonvt_wrap.d 


# Each subdirectory must supply rules for building sources it contributes
external/geojson-vt-cpp/src/%.o: ../external/geojson-vt-cpp/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


