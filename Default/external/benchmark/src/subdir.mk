################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/benchmark/src/benchmark.cc \
../external/benchmark/src/colorprint.cc \
../external/benchmark/src/commandlineflags.cc \
../external/benchmark/src/console_reporter.cc \
../external/benchmark/src/csv_reporter.cc \
../external/benchmark/src/json_reporter.cc \
../external/benchmark/src/log.cc \
../external/benchmark/src/re_posix.cc \
../external/benchmark/src/re_std.cc \
../external/benchmark/src/reporter.cc \
../external/benchmark/src/sleep.cc \
../external/benchmark/src/string_util.cc \
../external/benchmark/src/sysinfo.cc \
../external/benchmark/src/walltime.cc 

CC_DEPS += \
./external/benchmark/src/benchmark.d \
./external/benchmark/src/colorprint.d \
./external/benchmark/src/commandlineflags.d \
./external/benchmark/src/console_reporter.d \
./external/benchmark/src/csv_reporter.d \
./external/benchmark/src/json_reporter.d \
./external/benchmark/src/log.d \
./external/benchmark/src/re_posix.d \
./external/benchmark/src/re_std.d \
./external/benchmark/src/reporter.d \
./external/benchmark/src/sleep.d \
./external/benchmark/src/string_util.d \
./external/benchmark/src/sysinfo.d \
./external/benchmark/src/walltime.d 

OBJS += \
./external/benchmark/src/benchmark.o \
./external/benchmark/src/colorprint.o \
./external/benchmark/src/commandlineflags.o \
./external/benchmark/src/console_reporter.o \
./external/benchmark/src/csv_reporter.o \
./external/benchmark/src/json_reporter.o \
./external/benchmark/src/log.o \
./external/benchmark/src/re_posix.o \
./external/benchmark/src/re_std.o \
./external/benchmark/src/reporter.o \
./external/benchmark/src/sleep.o \
./external/benchmark/src/string_util.o \
./external/benchmark/src/sysinfo.o \
./external/benchmark/src/walltime.o 


# Each subdirectory must supply rules for building sources it contributes
external/benchmark/src/%.o: ../external/benchmark/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


