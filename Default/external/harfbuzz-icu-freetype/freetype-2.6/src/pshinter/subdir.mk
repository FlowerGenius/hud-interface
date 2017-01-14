################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshalgo.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshglob.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshinter.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshmod.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshpic.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshrec.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshalgo.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshglob.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshinter.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshmod.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshpic.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshrec.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshalgo.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshglob.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshinter.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshmod.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshpic.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/pshrec.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/pshinter/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


