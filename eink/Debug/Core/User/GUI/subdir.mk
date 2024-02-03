################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/GUI/GUI_Paint.c 

OBJS += \
./Core/User/GUI/GUI_Paint.o 

C_DEPS += \
./Core/User/GUI/GUI_Paint.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/GUI/%.o Core/User/GUI/%.su: ../Core/User/GUI/%.c Core/User/GUI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-GUI

clean-Core-2f-User-2f-GUI:
	-$(RM) ./Core/User/GUI/GUI_Paint.d ./Core/User/GUI/GUI_Paint.o ./Core/User/GUI/GUI_Paint.su

.PHONY: clean-Core-2f-User-2f-GUI

