################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/WVR/motor_bord.c \
../Core/Src/WVR/uart_msg.c 

OBJS += \
./Core/Src/WVR/motor_bord.o \
./Core/Src/WVR/uart_msg.o 

C_DEPS += \
./Core/Src/WVR/motor_bord.d \
./Core/Src/WVR/uart_msg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/WVR/%.o Core/Src/WVR/%.su Core/Src/WVR/%.cyclo: ../Core/Src/WVR/%.c Core/Src/WVR/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-WVR

clean-Core-2f-Src-2f-WVR:
	-$(RM) ./Core/Src/WVR/motor_bord.cyclo ./Core/Src/WVR/motor_bord.d ./Core/Src/WVR/motor_bord.o ./Core/Src/WVR/motor_bord.su ./Core/Src/WVR/uart_msg.cyclo ./Core/Src/WVR/uart_msg.d ./Core/Src/WVR/uart_msg.o ./Core/Src/WVR/uart_msg.su

.PHONY: clean-Core-2f-Src-2f-WVR

