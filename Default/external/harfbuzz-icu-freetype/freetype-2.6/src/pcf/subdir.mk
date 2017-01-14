################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcf.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfdrivr.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfread.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfutil.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcf.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfdrivr.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfread.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfutil.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcf.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfdrivr.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfread.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/pcfutil.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/pcf/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


