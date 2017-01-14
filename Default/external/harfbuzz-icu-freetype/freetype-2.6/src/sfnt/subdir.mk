################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/pngshim.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfdriver.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfnt.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfntpic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfobjs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttbdf.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttcmap.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttkern.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttmtx.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttpost.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttsbit.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/pngshim.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfdriver.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfnt.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfntpic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfobjs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttbdf.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttcmap.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttkern.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttmtx.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttpost.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttsbit.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/pngshim.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfdriver.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfnt.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfntpic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/sfobjs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttbdf.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttcmap.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttkern.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttmtx.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttpost.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/ttsbit.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/sfnt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


