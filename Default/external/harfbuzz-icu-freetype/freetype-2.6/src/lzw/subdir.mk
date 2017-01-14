################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/ftlzw.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/ftzopen.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/ftlzw.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/ftzopen.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/ftlzw.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/ftzopen.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/lzw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


