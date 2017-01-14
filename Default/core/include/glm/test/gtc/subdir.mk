################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/include/glm/test/gtc/gtc_bitfield.cpp \
../core/include/glm/test/gtc/gtc_color_space.cpp \
../core/include/glm/test/gtc/gtc_constants.cpp \
../core/include/glm/test/gtc/gtc_epsilon.cpp \
../core/include/glm/test/gtc/gtc_functions.cpp \
../core/include/glm/test/gtc/gtc_integer.cpp \
../core/include/glm/test/gtc/gtc_matrix_access.cpp \
../core/include/glm/test/gtc/gtc_matrix_integer.cpp \
../core/include/glm/test/gtc/gtc_matrix_inverse.cpp \
../core/include/glm/test/gtc/gtc_matrix_transform.cpp \
../core/include/glm/test/gtc/gtc_noise.cpp \
../core/include/glm/test/gtc/gtc_packing.cpp \
../core/include/glm/test/gtc/gtc_quaternion.cpp \
../core/include/glm/test/gtc/gtc_random.cpp \
../core/include/glm/test/gtc/gtc_reciprocal.cpp \
../core/include/glm/test/gtc/gtc_round.cpp \
../core/include/glm/test/gtc/gtc_type_aligned.cpp \
../core/include/glm/test/gtc/gtc_type_precision.cpp \
../core/include/glm/test/gtc/gtc_type_ptr.cpp \
../core/include/glm/test/gtc/gtc_ulp.cpp \
../core/include/glm/test/gtc/gtc_user_defined_types.cpp \
../core/include/glm/test/gtc/gtc_vec1.cpp 

OBJS += \
./core/include/glm/test/gtc/gtc_bitfield.o \
./core/include/glm/test/gtc/gtc_color_space.o \
./core/include/glm/test/gtc/gtc_constants.o \
./core/include/glm/test/gtc/gtc_epsilon.o \
./core/include/glm/test/gtc/gtc_functions.o \
./core/include/glm/test/gtc/gtc_integer.o \
./core/include/glm/test/gtc/gtc_matrix_access.o \
./core/include/glm/test/gtc/gtc_matrix_integer.o \
./core/include/glm/test/gtc/gtc_matrix_inverse.o \
./core/include/glm/test/gtc/gtc_matrix_transform.o \
./core/include/glm/test/gtc/gtc_noise.o \
./core/include/glm/test/gtc/gtc_packing.o \
./core/include/glm/test/gtc/gtc_quaternion.o \
./core/include/glm/test/gtc/gtc_random.o \
./core/include/glm/test/gtc/gtc_reciprocal.o \
./core/include/glm/test/gtc/gtc_round.o \
./core/include/glm/test/gtc/gtc_type_aligned.o \
./core/include/glm/test/gtc/gtc_type_precision.o \
./core/include/glm/test/gtc/gtc_type_ptr.o \
./core/include/glm/test/gtc/gtc_ulp.o \
./core/include/glm/test/gtc/gtc_user_defined_types.o \
./core/include/glm/test/gtc/gtc_vec1.o 

CPP_DEPS += \
./core/include/glm/test/gtc/gtc_bitfield.d \
./core/include/glm/test/gtc/gtc_color_space.d \
./core/include/glm/test/gtc/gtc_constants.d \
./core/include/glm/test/gtc/gtc_epsilon.d \
./core/include/glm/test/gtc/gtc_functions.d \
./core/include/glm/test/gtc/gtc_integer.d \
./core/include/glm/test/gtc/gtc_matrix_access.d \
./core/include/glm/test/gtc/gtc_matrix_integer.d \
./core/include/glm/test/gtc/gtc_matrix_inverse.d \
./core/include/glm/test/gtc/gtc_matrix_transform.d \
./core/include/glm/test/gtc/gtc_noise.d \
./core/include/glm/test/gtc/gtc_packing.d \
./core/include/glm/test/gtc/gtc_quaternion.d \
./core/include/glm/test/gtc/gtc_random.d \
./core/include/glm/test/gtc/gtc_reciprocal.d \
./core/include/glm/test/gtc/gtc_round.d \
./core/include/glm/test/gtc/gtc_type_aligned.d \
./core/include/glm/test/gtc/gtc_type_precision.d \
./core/include/glm/test/gtc/gtc_type_ptr.d \
./core/include/glm/test/gtc/gtc_ulp.d \
./core/include/glm/test/gtc/gtc_user_defined_types.d \
./core/include/glm/test/gtc/gtc_vec1.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/glm/test/gtc/%.o: ../core/include/glm/test/gtc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


