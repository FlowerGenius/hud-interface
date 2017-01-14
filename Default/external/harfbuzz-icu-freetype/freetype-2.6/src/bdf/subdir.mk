################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdf.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdfdrivr.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdflib.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdf.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdfdrivr.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdflib.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdf.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdfdrivr.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/bdflib.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/bdf/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


