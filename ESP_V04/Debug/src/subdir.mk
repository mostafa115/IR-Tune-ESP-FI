################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO_program.c \
../src/HESP_prg.c \
../src/MRCC_program.c \
../src/SYSTICK_program.c \
../src/UART_Prog.c \
../src/main.c 

OBJS += \
./src/GPIO_program.o \
./src/HESP_prg.o \
./src/MRCC_program.o \
./src/SYSTICK_program.o \
./src/UART_Prog.o \
./src/main.o 

C_DEPS += \
./src/GPIO_program.d \
./src/HESP_prg.d \
./src/MRCC_program.d \
./src/SYSTICK_program.d \
./src/UART_Prog.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


