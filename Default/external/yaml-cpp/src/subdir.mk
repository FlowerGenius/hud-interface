################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../external/yaml-cpp/src/binary.cpp \
../external/yaml-cpp/src/convert.cpp \
../external/yaml-cpp/src/directives.cpp \
../external/yaml-cpp/src/emit.cpp \
../external/yaml-cpp/src/emitfromevents.cpp \
../external/yaml-cpp/src/emitter.cpp \
../external/yaml-cpp/src/emitterstate.cpp \
../external/yaml-cpp/src/emitterutils.cpp \
../external/yaml-cpp/src/exceptions.cpp \
../external/yaml-cpp/src/exp.cpp \
../external/yaml-cpp/src/memory.cpp \
../external/yaml-cpp/src/node.cpp \
../external/yaml-cpp/src/node_data.cpp \
../external/yaml-cpp/src/nodebuilder.cpp \
../external/yaml-cpp/src/nodeevents.cpp \
../external/yaml-cpp/src/null.cpp \
../external/yaml-cpp/src/ostream_wrapper.cpp \
../external/yaml-cpp/src/parse.cpp \
../external/yaml-cpp/src/parser.cpp \
../external/yaml-cpp/src/scanner.cpp \
../external/yaml-cpp/src/scanscalar.cpp \
../external/yaml-cpp/src/scantag.cpp \
../external/yaml-cpp/src/scantoken.cpp \
../external/yaml-cpp/src/simplekey.cpp \
../external/yaml-cpp/src/singledocparser.cpp \
../external/yaml-cpp/src/stream.cpp \
../external/yaml-cpp/src/tag.cpp 

OBJS += \
./external/yaml-cpp/src/binary.o \
./external/yaml-cpp/src/convert.o \
./external/yaml-cpp/src/directives.o \
./external/yaml-cpp/src/emit.o \
./external/yaml-cpp/src/emitfromevents.o \
./external/yaml-cpp/src/emitter.o \
./external/yaml-cpp/src/emitterstate.o \
./external/yaml-cpp/src/emitterutils.o \
./external/yaml-cpp/src/exceptions.o \
./external/yaml-cpp/src/exp.o \
./external/yaml-cpp/src/memory.o \
./external/yaml-cpp/src/node.o \
./external/yaml-cpp/src/node_data.o \
./external/yaml-cpp/src/nodebuilder.o \
./external/yaml-cpp/src/nodeevents.o \
./external/yaml-cpp/src/null.o \
./external/yaml-cpp/src/ostream_wrapper.o \
./external/yaml-cpp/src/parse.o \
./external/yaml-cpp/src/parser.o \
./external/yaml-cpp/src/scanner.o \
./external/yaml-cpp/src/scanscalar.o \
./external/yaml-cpp/src/scantag.o \
./external/yaml-cpp/src/scantoken.o \
./external/yaml-cpp/src/simplekey.o \
./external/yaml-cpp/src/singledocparser.o \
./external/yaml-cpp/src/stream.o \
./external/yaml-cpp/src/tag.o 

CPP_DEPS += \
./external/yaml-cpp/src/binary.d \
./external/yaml-cpp/src/convert.d \
./external/yaml-cpp/src/directives.d \
./external/yaml-cpp/src/emit.d \
./external/yaml-cpp/src/emitfromevents.d \
./external/yaml-cpp/src/emitter.d \
./external/yaml-cpp/src/emitterstate.d \
./external/yaml-cpp/src/emitterutils.d \
./external/yaml-cpp/src/exceptions.d \
./external/yaml-cpp/src/exp.d \
./external/yaml-cpp/src/memory.d \
./external/yaml-cpp/src/node.d \
./external/yaml-cpp/src/node_data.d \
./external/yaml-cpp/src/nodebuilder.d \
./external/yaml-cpp/src/nodeevents.d \
./external/yaml-cpp/src/null.d \
./external/yaml-cpp/src/ostream_wrapper.d \
./external/yaml-cpp/src/parse.d \
./external/yaml-cpp/src/parser.d \
./external/yaml-cpp/src/scanner.d \
./external/yaml-cpp/src/scanscalar.d \
./external/yaml-cpp/src/scantag.d \
./external/yaml-cpp/src/scantoken.d \
./external/yaml-cpp/src/simplekey.d \
./external/yaml-cpp/src/singledocparser.d \
./external/yaml-cpp/src/stream.d \
./external/yaml-cpp/src/tag.d 


# Each subdirectory must supply rules for building sources it contributes
external/yaml-cpp/src/%.o: ../external/yaml-cpp/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


