################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/variant/test/t/binary_visitor_1.cpp \
../core/include/variant/test/t/binary_visitor_2.cpp \
../core/include/variant/test/t/binary_visitor_3.cpp \
../core/include/variant/test/t/binary_visitor_4.cpp \
../core/include/variant/test/t/binary_visitor_5.cpp \
../core/include/variant/test/t/binary_visitor_6.cpp \
../core/include/variant/test/t/issue21.cpp \
../core/include/variant/test/t/mutating_visitor.cpp \
../core/include/variant/test/t/optional.cpp \
../core/include/variant/test/t/recursive_wrapper.cpp \
../core/include/variant/test/t/sizeof.cpp \
../core/include/variant/test/t/unary_visitor.cpp \
../core/include/variant/test/t/variant.cpp 

OBJS += \
./core/include/variant/test/t/binary_visitor_1.o \
./core/include/variant/test/t/binary_visitor_2.o \
./core/include/variant/test/t/binary_visitor_3.o \
./core/include/variant/test/t/binary_visitor_4.o \
./core/include/variant/test/t/binary_visitor_5.o \
./core/include/variant/test/t/binary_visitor_6.o \
./core/include/variant/test/t/issue21.o \
./core/include/variant/test/t/mutating_visitor.o \
./core/include/variant/test/t/optional.o \
./core/include/variant/test/t/recursive_wrapper.o \
./core/include/variant/test/t/sizeof.o \
./core/include/variant/test/t/unary_visitor.o \
./core/include/variant/test/t/variant.o 

CPP_DEPS += \
./core/include/variant/test/t/binary_visitor_1.d \
./core/include/variant/test/t/binary_visitor_2.d \
./core/include/variant/test/t/binary_visitor_3.d \
./core/include/variant/test/t/binary_visitor_4.d \
./core/include/variant/test/t/binary_visitor_5.d \
./core/include/variant/test/t/binary_visitor_6.d \
./core/include/variant/test/t/issue21.d \
./core/include/variant/test/t/mutating_visitor.d \
./core/include/variant/test/t/optional.d \
./core/include/variant/test/t/recursive_wrapper.d \
./core/include/variant/test/t/sizeof.d \
./core/include/variant/test/t/unary_visitor.d \
./core/include/variant/test/t/variant.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/variant/test/t/%.o: ../core/include/variant/test/t/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


