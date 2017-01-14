################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/apinames.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_afm.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_bbox.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_trig.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/apinames.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_afm.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_bbox.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_trig.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/apinames.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_afm.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_bbox.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/test_trig.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/tools/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


