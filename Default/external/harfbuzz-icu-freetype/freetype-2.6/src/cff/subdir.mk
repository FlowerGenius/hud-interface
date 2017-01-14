################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2arrst.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2blues.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2error.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2font.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2ft.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2hints.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2intrp.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2read.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2stack.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cff.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffcmap.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffdrivr.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffgload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffload.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffobjs.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffparse.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffpic.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2arrst.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2blues.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2error.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2font.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2ft.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2hints.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2intrp.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2read.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2stack.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cff.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffcmap.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffdrivr.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffgload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffload.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffobjs.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffparse.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffpic.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2arrst.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2blues.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2error.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2font.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2ft.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2hints.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2intrp.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2read.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cf2stack.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cff.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffcmap.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffdrivr.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffgload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffload.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffobjs.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffparse.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/cff/cffpic.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/cff/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/cff/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


