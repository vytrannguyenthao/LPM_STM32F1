################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/e-Paper/EPD_1in54b.c \
../Core/User/e-Paper/EPD_2in7b.c 

OBJS += \
./Core/User/e-Paper/EPD_1in54b.o \
./Core/User/e-Paper/EPD_2in7b.o 

C_DEPS += \
./Core/User/e-Paper/EPD_1in54b.d \
./Core/User/e-Paper/EPD_2in7b.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/e-Paper/%.o Core/User/e-Paper/%.su: ../Core/User/e-Paper/%.c Core/User/e-Paper/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-e-2d-Paper

clean-Core-2f-User-2f-e-2d-Paper:
	-$(RM) ./Core/User/e-Paper/EPD_1in54b.d ./Core/User/e-Paper/EPD_1in54b.o ./Core/User/e-Paper/EPD_1in54b.su ./Core/User/e-Paper/EPD_2in7b.d ./Core/User/e-Paper/EPD_2in7b.o ./Core/User/e-Paper/EPD_2in7b.su

.PHONY: clean-Core-2f-User-2f-e-2d-Paper

