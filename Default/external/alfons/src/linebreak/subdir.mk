################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external/alfons/src/linebreak/linebreak.c \
../external/alfons/src/linebreak/linebreakdata.c \
../external/alfons/src/linebreak/linebreakdef.c 

OBJS += \
./external/alfons/src/linebreak/linebreak.o \
./external/alfons/src/linebreak/linebreakdata.o \
./external/alfons/src/linebreak/linebreakdef.o 

C_DEPS += \
./external/alfons/src/linebreak/linebreak.d \
./external/alfons/src/linebreak/linebreakdata.d \
./external/alfons/src/linebreak/linebreakdef.d 


# Each subdirectory must supply rules for building sources it contributes
external/alfons/src/linebreak/%.o: ../external/alfons/src/linebreak/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


