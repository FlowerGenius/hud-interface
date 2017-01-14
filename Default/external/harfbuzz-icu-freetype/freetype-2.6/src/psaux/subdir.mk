################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/afmparse.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psaux.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psauxmod.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psconv.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psobjs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/t1cmap.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/t1decode.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/afmparse.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psaux.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psauxmod.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psconv.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psobjs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/t1cmap.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/t1decode.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/afmparse.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psaux.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psauxmod.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psconv.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/psobjs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/t1cmap.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/t1decode.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/psaux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


