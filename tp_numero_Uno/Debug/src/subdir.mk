################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Menu.c \
../src/funciones.c \
../src/tp_numero_Uno.c 

OBJS += \
./src/Menu.o \
./src/funciones.o \
./src/tp_numero_Uno.o 

C_DEPS += \
./src/Menu.d \
./src/funciones.d \
./src/tp_numero_Uno.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


