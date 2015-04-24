################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ASerialLdd3.c \
../Generated_Code/Bit1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/Cpu.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/UART3.c \
../Generated_Code/Vectors.c 

OBJS += \
./Generated_Code/ASerialLdd3.o \
./Generated_Code/Bit1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/Cpu.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/UART3.o \
./Generated_Code/Vectors.o 

C_DEPS += \
./Generated_Code/ASerialLdd3.d \
./Generated_Code/Bit1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/Cpu.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/UART3.d \
./Generated_Code/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/sonko-mbuvi/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/sonko-mbuvi/eclipse/ProcessorExpert/lib/Kinetis/iofiles" -I"/home/sonko-mbuvi/Desktop/systemc/k60_uart3/Sources" -I"/home/sonko-mbuvi/Desktop/systemc/k60_uart3/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


