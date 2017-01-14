################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/truetype.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttdriver.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttgload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttgxvar.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttinterp.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttobjs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttpic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttpload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttsubpix.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/truetype.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttdriver.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttgload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttgxvar.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttinterp.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttobjs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttpic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttpload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttsubpix.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/truetype.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttdriver.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttgload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttgxvar.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttinterp.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttobjs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttpic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttpload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/ttsubpix.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/truetype/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


