################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Passenger.c \
../UTN.c \
../main.c \
../parser.c 

OBJS += \
./Controller.o \
./Passenger.o \
./UTN.o \
./main.o \
./parser.o 

C_DEPS += \
./Controller.d \
./Passenger.d \
./UTN.d \
./main.d \
./parser.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


