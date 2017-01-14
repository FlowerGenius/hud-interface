################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcache.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcbasic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftccache.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftccmap.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcglyph.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcimage.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcmanag.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcmru.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcsbits.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcache.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcbasic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftccache.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftccmap.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcglyph.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcimage.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcmanag.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcmru.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcsbits.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcache.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcbasic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftccache.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftccmap.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcglyph.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcimage.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcmanag.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcmru.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cache/ftcsbits.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/cache/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/cache/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


