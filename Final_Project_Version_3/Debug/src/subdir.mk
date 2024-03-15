################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Amr_Diab_Frames.c \
../src/DAC_program.c \
../src/EXTI_program.c \
../src/GPIO_program.c \
../src/GPTIM\ _program.c \
../src/HESP_prg.c \
../src/IR_program.c \
../src/MRCC_program.c \
../src/NVIC_program.c \
../src/SPI.c \
../src/STP_program.c \
../src/SYSTICK_program.c \
../src/TFT_program.c \
../src/Tamer_Ashour_Frames.c \
../src/UART_Prog.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/Amr_Diab_Frames.o \
./src/DAC_program.o \
./src/EXTI_program.o \
./src/GPIO_program.o \
./src/GPTIM\ _program.o \
./src/HESP_prg.o \
./src/IR_program.o \
./src/MRCC_program.o \
./src/NVIC_program.o \
./src/SPI.o \
./src/STP_program.o \
./src/SYSTICK_program.o \
./src/TFT_program.o \
./src/Tamer_Ashour_Frames.o \
./src/UART_Prog.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/Amr_Diab_Frames.d \
./src/DAC_program.d \
./src/EXTI_program.d \
./src/GPIO_program.d \
./src/GPTIM\ _program.d \
./src/HESP_prg.d \
./src/IR_program.d \
./src/MRCC_program.d \
./src/NVIC_program.d \
./src/SPI.d \
./src/STP_program.d \
./src/SYSTICK_program.d \
./src/TFT_program.d \
./src/Tamer_Ashour_Frames.d \
./src/UART_Prog.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/GPTIM\ _program.o: ../src/GPTIM\ _program.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"src/GPTIM _program.d" -MT"src/GPTIM\ _program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


