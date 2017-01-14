################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/raster/ftraster.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/raster/ftrend1.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/raster/raster.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/raster/rastpic.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/ftraster.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/ftrend1.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/raster.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/rastpic.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/ftraster.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/ftrend1.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/raster.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/raster/rastpic.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/raster/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/raster/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


