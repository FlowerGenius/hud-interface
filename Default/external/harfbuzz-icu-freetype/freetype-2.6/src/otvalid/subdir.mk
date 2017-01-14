################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvalid.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvbase.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvcommn.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgdef.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgpos.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgsub.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvjstf.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvmath.c \
../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvmod.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvalid.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvbase.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvcommn.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgdef.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgpos.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgsub.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvjstf.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvmath.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvmod.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvalid.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvbase.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvcommn.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgdef.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgpos.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvgsub.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvjstf.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvmath.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/otvmod.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/otvalid/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


