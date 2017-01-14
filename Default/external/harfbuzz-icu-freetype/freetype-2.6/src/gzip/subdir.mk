################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/adler32.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/ftgzip.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infblock.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infcodes.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/inflate.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/inftrees.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infutil.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/zutil.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/adler32.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/ftgzip.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infblock.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infcodes.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/inflate.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/inftrees.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infutil.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/zutil.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/adler32.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/ftgzip.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infblock.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infcodes.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/inflate.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/inftrees.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/infutil.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/zutil.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/gzip/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


