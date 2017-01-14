################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/ftdebug.c \
../external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/ftsystem.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/ftdebug.o \
./external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/ftsystem.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/ftdebug.d \
./external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/ftsystem.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/builds/amiga/src/base/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


