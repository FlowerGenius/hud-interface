################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfr.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrcmap.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrdrivr.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrgload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrobjs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrsbit.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfr.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrcmap.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrdrivr.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrgload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrobjs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrsbit.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfr.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrcmap.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrdrivr.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrgload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrobjs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/pfrsbit.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/pfr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


