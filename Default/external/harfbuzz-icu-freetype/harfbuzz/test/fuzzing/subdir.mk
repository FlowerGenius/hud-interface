################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/harfbuzz-icu-freetype/harfbuzz/test/fuzzing/hb-fuzzer.cc 

CC_DEPS += \
./external/harfbuzz-icu-freetype/harfbuzz/test/fuzzing/hb-fuzzer.d 

OBJS += \
./external/harfbuzz-icu-freetype/harfbuzz/test/fuzzing/hb-fuzzer.o 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/harfbuzz/test/fuzzing/%.o: ../external/harfbuzz-icu-freetype/harfbuzz/test/fuzzing/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


