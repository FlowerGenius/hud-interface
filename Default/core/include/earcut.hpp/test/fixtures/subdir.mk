################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/earcut.hpp/test/fixtures/bad_hole.cpp \
../core/include/earcut.hpp/test/fixtures/building.cpp \
../core/include/earcut.hpp/test/fixtures/degenerate.cpp \
../core/include/earcut.hpp/test/fixtures/dude.cpp \
../core/include/earcut.hpp/test/fixtures/eberly-6.cpp \
../core/include/earcut.hpp/test/fixtures/empty_square.cpp \
../core/include/earcut.hpp/test/fixtures/hilbert.cpp \
../core/include/earcut.hpp/test/fixtures/hole_touching_outer.cpp \
../core/include/earcut.hpp/test/fixtures/issue16.cpp \
../core/include/earcut.hpp/test/fixtures/issue17.cpp \
../core/include/earcut.hpp/test/fixtures/issue29.cpp \
../core/include/earcut.hpp/test/fixtures/issue34.cpp \
../core/include/earcut.hpp/test/fixtures/issue35.cpp \
../core/include/earcut.hpp/test/fixtures/issue45.cpp \
../core/include/earcut.hpp/test/fixtures/outside_ring.cpp \
../core/include/earcut.hpp/test/fixtures/park.cpp \
../core/include/earcut.hpp/test/fixtures/self_touching.cpp \
../core/include/earcut.hpp/test/fixtures/simplified_us_border.cpp \
../core/include/earcut.hpp/test/fixtures/steiner.cpp \
../core/include/earcut.hpp/test/fixtures/touching_holes.cpp \
../core/include/earcut.hpp/test/fixtures/water.cpp \
../core/include/earcut.hpp/test/fixtures/water2.cpp \
../core/include/earcut.hpp/test/fixtures/water3.cpp \
../core/include/earcut.hpp/test/fixtures/water3b.cpp \
../core/include/earcut.hpp/test/fixtures/water4.cpp \
../core/include/earcut.hpp/test/fixtures/water_huge.cpp \
../core/include/earcut.hpp/test/fixtures/water_huge2.cpp 

OBJS += \
./core/include/earcut.hpp/test/fixtures/bad_hole.o \
./core/include/earcut.hpp/test/fixtures/building.o \
./core/include/earcut.hpp/test/fixtures/degenerate.o \
./core/include/earcut.hpp/test/fixtures/dude.o \
./core/include/earcut.hpp/test/fixtures/eberly-6.o \
./core/include/earcut.hpp/test/fixtures/empty_square.o \
./core/include/earcut.hpp/test/fixtures/hilbert.o \
./core/include/earcut.hpp/test/fixtures/hole_touching_outer.o \
./core/include/earcut.hpp/test/fixtures/issue16.o \
./core/include/earcut.hpp/test/fixtures/issue17.o \
./core/include/earcut.hpp/test/fixtures/issue29.o \
./core/include/earcut.hpp/test/fixtures/issue34.o \
./core/include/earcut.hpp/test/fixtures/issue35.o \
./core/include/earcut.hpp/test/fixtures/issue45.o \
./core/include/earcut.hpp/test/fixtures/outside_ring.o \
./core/include/earcut.hpp/test/fixtures/park.o \
./core/include/earcut.hpp/test/fixtures/self_touching.o \
./core/include/earcut.hpp/test/fixtures/simplified_us_border.o \
./core/include/earcut.hpp/test/fixtures/steiner.o \
./core/include/earcut.hpp/test/fixtures/touching_holes.o \
./core/include/earcut.hpp/test/fixtures/water.o \
./core/include/earcut.hpp/test/fixtures/water2.o \
./core/include/earcut.hpp/test/fixtures/water3.o \
./core/include/earcut.hpp/test/fixtures/water3b.o \
./core/include/earcut.hpp/test/fixtures/water4.o \
./core/include/earcut.hpp/test/fixtures/water_huge.o \
./core/include/earcut.hpp/test/fixtures/water_huge2.o 

CPP_DEPS += \
./core/include/earcut.hpp/test/fixtures/bad_hole.d \
./core/include/earcut.hpp/test/fixtures/building.d \
./core/include/earcut.hpp/test/fixtures/degenerate.d \
./core/include/earcut.hpp/test/fixtures/dude.d \
./core/include/earcut.hpp/test/fixtures/eberly-6.d \
./core/include/earcut.hpp/test/fixtures/empty_square.d \
./core/include/earcut.hpp/test/fixtures/hilbert.d \
./core/include/earcut.hpp/test/fixtures/hole_touching_outer.d \
./core/include/earcut.hpp/test/fixtures/issue16.d \
./core/include/earcut.hpp/test/fixtures/issue17.d \
./core/include/earcut.hpp/test/fixtures/issue29.d \
./core/include/earcut.hpp/test/fixtures/issue34.d \
./core/include/earcut.hpp/test/fixtures/issue35.d \
./core/include/earcut.hpp/test/fixtures/issue45.d \
./core/include/earcut.hpp/test/fixtures/outside_ring.d \
./core/include/earcut.hpp/test/fixtures/park.d \
./core/include/earcut.hpp/test/fixtures/self_touching.d \
./core/include/earcut.hpp/test/fixtures/simplified_us_border.d \
./core/include/earcut.hpp/test/fixtures/steiner.d \
./core/include/earcut.hpp/test/fixtures/touching_holes.d \
./core/include/earcut.hpp/test/fixtures/water.d \
./core/include/earcut.hpp/test/fixtures/water2.d \
./core/include/earcut.hpp/test/fixtures/water3.d \
./core/include/earcut.hpp/test/fixtures/water3b.d \
./core/include/earcut.hpp/test/fixtures/water4.d \
./core/include/earcut.hpp/test/fixtures/water_huge.d \
./core/include/earcut.hpp/test/fixtures/water_huge2.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/earcut.hpp/test/fixtures/%.o: ../core/include/earcut.hpp/test/fixtures/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


