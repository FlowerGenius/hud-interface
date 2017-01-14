################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftgrays.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftsmooth.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftspic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/smooth.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftgrays.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftsmooth.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftspic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/smooth.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftgrays.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftsmooth.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/ftspic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/smooth.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/smooth/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


