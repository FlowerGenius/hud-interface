################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42drivr.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42objs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42parse.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/type42/type42.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42drivr.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42objs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42parse.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/type42.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42drivr.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42objs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/t42parse.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/type42/type42.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/type42/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/type42/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


