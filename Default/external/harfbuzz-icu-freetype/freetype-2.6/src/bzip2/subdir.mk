################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/bzip2/ftbzip2.c 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bzip2/ftbzip2.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/bzip2/ftbzip2.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/bzip2/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/bzip2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


