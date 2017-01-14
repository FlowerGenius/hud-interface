################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/variant/test/bench_variant.cpp \
../core/include/variant/test/binary_visitor_test.cpp \
../core/include/variant/test/boost_variant_hello_world.cpp \
../core/include/variant/test/our_variant_hello_world.cpp \
../core/include/variant/test/recursive_wrapper_test.cpp \
../core/include/variant/test/reference_wrapper_test.cpp \
../core/include/variant/test/unique_ptr_test.cpp \
../core/include/variant/test/unit.cpp 

OBJS += \
./core/include/variant/test/bench_variant.o \
./core/include/variant/test/binary_visitor_test.o \
./core/include/variant/test/boost_variant_hello_world.o \
./core/include/variant/test/our_variant_hello_world.o \
./core/include/variant/test/recursive_wrapper_test.o \
./core/include/variant/test/reference_wrapper_test.o \
./core/include/variant/test/unique_ptr_test.o \
./core/include/variant/test/unit.o 

CPP_DEPS += \
./core/include/variant/test/bench_variant.d \
./core/include/variant/test/binary_visitor_test.d \
./core/include/variant/test/boost_variant_hello_world.d \
./core/include/variant/test/our_variant_hello_world.d \
./core/include/variant/test/recursive_wrapper_test.d \
./core/include/variant/test/reference_wrapper_test.d \
./core/include/variant/test/unique_ptr_test.d \
./core/include/variant/test/unit.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/variant/test/%.o: ../core/include/variant/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


