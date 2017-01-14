################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-actions_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-cardinalities_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-actions_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-function-mockers_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-internal-utils_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-matchers_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-internal-utils_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-matchers_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-more-actions_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-nice-strict_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-port_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock-spec-builders_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_all_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_ex_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_leak_test_.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_link2_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_link_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_output_test_.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_stress_test.cc \
../external/yaml-cpp/test/gmock-1.7.0/test/gmock_test.cc 

CC_DEPS += \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-actions_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-cardinalities_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-actions_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-function-mockers_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-internal-utils_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-matchers_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-internal-utils_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-matchers_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-more-actions_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-nice-strict_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-port_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-spec-builders_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_all_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_ex_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_leak_test_.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_link2_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_link_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_output_test_.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_stress_test.d \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_test.d 

OBJS += \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-actions_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-cardinalities_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-actions_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-function-mockers_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-internal-utils_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-generated-matchers_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-internal-utils_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-matchers_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-more-actions_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-nice-strict_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-port_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock-spec-builders_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_all_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_ex_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_leak_test_.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_link2_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_link_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_output_test_.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_stress_test.o \
./external/yaml-cpp/test/gmock-1.7.0/test/gmock_test.o 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/gmock-1.7.0/test/%.o: ../external/yaml-cpp/test/gmock-1.7.0/test/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


