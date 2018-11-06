################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ActivationFunctions.cpp \
../src/Connection.cpp \
../src/InputNeuron.cpp \
../src/NeuralNetwork.cpp \
../src/Neuro1.cpp \
../src/Neuron.cpp \
../src/WorkingNeuron.cpp 

OBJS += \
./src/ActivationFunctions.o \
./src/Connection.o \
./src/InputNeuron.o \
./src/NeuralNetwork.o \
./src/Neuro1.o \
./src/Neuron.o \
./src/WorkingNeuron.o 

CPP_DEPS += \
./src/ActivationFunctions.d \
./src/Connection.d \
./src/InputNeuron.d \
./src/NeuralNetwork.d \
./src/Neuro1.d \
./src/Neuron.d \
./src/WorkingNeuron.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


