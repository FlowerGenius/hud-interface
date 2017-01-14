################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afangles.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afblue.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afcjk.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afdummy.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afglobal.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afhints.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afindic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/aflatin.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/aflatin2.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afloader.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afmodule.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afpic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afranges.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afshaper.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afwarp.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/autofit.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afangles.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afblue.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afcjk.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afdummy.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afglobal.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afhints.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afindic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/aflatin.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/aflatin2.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afloader.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afmodule.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afpic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afranges.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afshaper.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afwarp.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/autofit.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afangles.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afblue.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afcjk.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afdummy.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afglobal.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afhints.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afindic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/aflatin.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/aflatin2.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afloader.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afmodule.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afpic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afranges.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afshaper.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/afwarp.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/autofit.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/autofit/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


