################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-cplusplus.cc 

C_SRCS += \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-blob.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-buffer.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-c.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-common.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-font.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-object.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-ot-tag.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-set.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-shape.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-unicode.c \
../external/harfbuzz-icu-freetype/harfbuzz/test/api/test-version.c 

CC_DEPS += \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-cplusplus.d 

OBJS += \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-blob.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-buffer.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-c.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-common.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-cplusplus.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-font.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-object.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-ot-tag.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-set.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-shape.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-unicode.o \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-version.o 

C_DEPS += \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-blob.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-buffer.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-c.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-common.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-font.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-object.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-ot-tag.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-set.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-shape.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-unicode.d \
./external/harfbuzz-icu-freetype/harfbuzz/test/api/test-version.d 


# Each subdirectory must supply rules for building sources it contributes
external/harfbuzz-icu-freetype/harfbuzz/test/api/%.o: ../external/harfbuzz-icu-freetype/harfbuzz/test/api/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

external/harfbuzz-icu-freetype/harfbuzz/test/api/%.o: ../external/harfbuzz-icu-freetype/harfbuzz/test/api/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


