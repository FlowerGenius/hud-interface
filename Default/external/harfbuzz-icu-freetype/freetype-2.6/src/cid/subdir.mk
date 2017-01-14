################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidgload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidobjs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidparse.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidriver.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/type1cid.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidgload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidobjs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidparse.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidriver.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/type1cid.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidgload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidobjs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidparse.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/cidriver.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cid/type1cid.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/cid/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/cid/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


