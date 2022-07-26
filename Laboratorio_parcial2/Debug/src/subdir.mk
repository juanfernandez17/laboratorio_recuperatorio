################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Laboratorio_parcial2.c \
../src/LinkedList.c \
../src/Pokemon.c \
../src/controller.c \
../src/parser.c \
../src/utn.c 

C_DEPS += \
./src/Laboratorio_parcial2.d \
./src/LinkedList.d \
./src/Pokemon.d \
./src/controller.d \
./src/parser.d \
./src/utn.d 

OBJS += \
./src/Laboratorio_parcial2.o \
./src/LinkedList.o \
./src/Pokemon.o \
./src/controller.o \
./src/parser.o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Laboratorio_parcial2.d ./src/Laboratorio_parcial2.o ./src/LinkedList.d ./src/LinkedList.o ./src/Pokemon.d ./src/Pokemon.o ./src/controller.d ./src/controller.o ./src/parser.d ./src/parser.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

