################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1afm.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1driver.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1gload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1load.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1objs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1parse.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/type1.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1afm.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1driver.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1gload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1load.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1objs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1parse.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/type1.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1afm.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1driver.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1gload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1load.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1objs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/t1parse.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type1/type1.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/type1/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/type1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


