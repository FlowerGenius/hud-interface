################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/yaml-cpp/test/integration/emitter_test.cpp \
../external/yaml-cpp/test/integration/encoding_test.cpp \
../external/yaml-cpp/test/integration/gen_emitter_test.cpp \
../external/yaml-cpp/test/integration/handler_spec_test.cpp \
../external/yaml-cpp/test/integration/handler_test.cpp \
../external/yaml-cpp/test/integration/load_node_test.cpp \
../external/yaml-cpp/test/integration/node_spec_test.cpp 

OBJS += \
./external/yaml-cpp/test/integration/emitter_test.o \
./external/yaml-cpp/test/integration/encoding_test.o \
./external/yaml-cpp/test/integration/gen_emitter_test.o \
./external/yaml-cpp/test/integration/handler_spec_test.o \
./external/yaml-cpp/test/integration/handler_test.o \
./external/yaml-cpp/test/integration/load_node_test.o \
./external/yaml-cpp/test/integration/node_spec_test.o 

CPP_DEPS += \
./external/yaml-cpp/test/integration/emitter_test.d \
./external/yaml-cpp/test/integration/encoding_test.d \
./external/yaml-cpp/test/integration/gen_emitter_test.d \
./external/yaml-cpp/test/integration/handler_spec_test.d \
./external/yaml-cpp/test/integration/handler_test.d \
./external/yaml-cpp/test/integration/load_node_test.d \
./external/yaml-cpp/test/integration/node_spec_test.d 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/test/integration/%.o: ../external/yaml-cpp/test/integration/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


