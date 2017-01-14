################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/variant/test/compilation_failure/default_constructor.cpp \
../core/include/variant/test/compilation_failure/empty_typelist.cpp \
../core/include/variant/test/compilation_failure/equality.cpp \
../core/include/variant/test/compilation_failure/get_type.cpp \
../core/include/variant/test/compilation_failure/is_type.cpp \
../core/include/variant/test/compilation_failure/mutating_visitor_on_const.cpp \
../core/include/variant/test/compilation_failure/no-reference.cpp 

OBJS += \
./core/include/variant/test/compilation_failure/default_constructor.o \
./core/include/variant/test/compilation_failure/empty_typelist.o \
./core/include/variant/test/compilation_failure/equality.o \
./core/include/variant/test/compilation_failure/get_type.o \
./core/include/variant/test/compilation_failure/is_type.o \
./core/include/variant/test/compilation_failure/mutating_visitor_on_const.o \
./core/include/variant/test/compilation_failure/no-reference.o 

CPP_DEPS += \
./core/include/variant/test/compilation_failure/default_constructor.d \
./core/include/variant/test/compilation_failure/empty_typelist.d \
./core/include/variant/test/compilation_failure/equality.d \
./core/include/variant/test/compilation_failure/get_type.d \
./core/include/variant/test/compilation_failure/is_type.d \
./core/include/variant/test/compilation_failure/mutating_visitor_on_const.d \
./core/include/variant/test/compilation_failure/no-reference.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/variant/test/compilation_failure/%.o: ../core/include/variant/test/compilation_failure/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


