################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/harfbuzz-icu-freetype/harfbuzz/util/ansi-print.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/hb-fc.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/hb-ot-shape-closure.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/hb-shape.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/hb-view.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/helper-cairo-ansi.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/helper-cairo.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/options.cc \
../external/harfbuzz-icu-freetype/harfbuzz/util/view-cairo.cc 

C_SRCS += \
../external/harfbuzz-icu-freetype/harfbuzz/util/hb-fc-list.c 

CC_DEPS += \
./external/harfbuzz-icu-freetype/harfbuzz/util/ansi-print.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-fc.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-ot-shape-closure.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-shape.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-view.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/helper-cairo-ansi.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/helper-cairo.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/options.d \
./external/harfbuzz-icu-freetype/harfbuzz/util/view-cairo.d 

OBJS += \
./external/harfbuzz-icu-freetype/harfbuzz/util/ansi-print.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-fc-list.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-fc.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-ot-shape-closure.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-shape.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-view.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/helper-cairo-ansi.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/helper-cairo.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/options.o \
./external/harfbuzz-icu-freetype/harfbuzz/util/view-cairo.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/harfbuzz/util/hb-fc-list.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/harfbuzz/util/%.o: ../external/harfbuzz-icu-freetype/harfbuzz/util/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

external/harfbuzz-icu-freetype/harfbuzz/util/%.o: ../external/harfbuzz-icu-freetype/harfbuzz/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


