################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../core/include/earcut.hpp/test/comparison/libtess2/bucketalloc.c \
../core/include/earcut.hpp/test/comparison/libtess2/dict.c \
../core/include/earcut.hpp/test/comparison/libtess2/geom.c \
../core/include/earcut.hpp/test/comparison/libtess2/mesh.c \
../core/include/earcut.hpp/test/comparison/libtess2/priorityq.c \
../core/include/earcut.hpp/test/comparison/libtess2/sweep.c \
../core/include/earcut.hpp/test/comparison/libtess2/tess.c 

OBJS += \
./core/include/earcut.hpp/test/comparison/libtess2/bucketalloc.o \
./core/include/earcut.hpp/test/comparison/libtess2/dict.o \
./core/include/earcut.hpp/test/comparison/libtess2/geom.o \
./core/include/earcut.hpp/test/comparison/libtess2/mesh.o \
./core/include/earcut.hpp/test/comparison/libtess2/priorityq.o \
./core/include/earcut.hpp/test/comparison/libtess2/sweep.o \
./core/include/earcut.hpp/test/comparison/libtess2/tess.o 

C_DEPS += \
./core/include/earcut.hpp/test/comparison/libtess2/bucketalloc.d \
./core/include/earcut.hpp/test/comparison/libtess2/dict.d \
./core/include/earcut.hpp/test/comparison/libtess2/geom.d \
./core/include/earcut.hpp/test/comparison/libtess2/mesh.d \
./core/include/earcut.hpp/test/comparison/libtess2/priorityq.d \
./core/include/earcut.hpp/test/comparison/libtess2/sweep.d \
./core/include/earcut.hpp/test/comparison/libtess2/tess.d 


# Each subdirectory must supply rules for building sources it contributes
core/include/earcut.hpp/test/comparison/libtess2/%.o: ../core/include/earcut.hpp/test/comparison/libtess2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


