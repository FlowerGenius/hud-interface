################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/ftfuzzer.cc \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/ftmutator.cc \
../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/runinput.cc 

CC_DEPS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/ftfuzzer.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/ftmutator.d \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/runinput.d 

OBJS += \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/ftfuzzer.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/ftmutator.o \
./external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/runinput.o 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/%.o: ../external/harfbuzz-icu-freetype/freetype-2.6/src/tools/ftfuzzer/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


