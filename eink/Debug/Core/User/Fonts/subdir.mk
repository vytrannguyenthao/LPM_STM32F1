################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/Fonts/font12.c \
../Core/User/Fonts/font16.c \
../Core/User/Fonts/font20.c \
../Core/User/Fonts/font24.c \
../Core/User/Fonts/font32.c \
../Core/User/Fonts/font48.c \
../Core/User/Fonts/font8.c 

OBJS += \
./Core/User/Fonts/font12.o \
./Core/User/Fonts/font16.o \
./Core/User/Fonts/font20.o \
./Core/User/Fonts/font24.o \
./Core/User/Fonts/font32.o \
./Core/User/Fonts/font48.o \
./Core/User/Fonts/font8.o 

C_DEPS += \
./Core/User/Fonts/font12.d \
./Core/User/Fonts/font16.d \
./Core/User/Fonts/font20.d \
./Core/User/Fonts/font24.d \
./Core/User/Fonts/font32.d \
./Core/User/Fonts/font48.d \
./Core/User/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/Fonts/%.o Core/User/Fonts/%.su: ../Core/User/Fonts/%.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-Fonts

clean-Core-2f-User-2f-Fonts:
	-$(RM) ./Core/User/Fonts/font12.d ./Core/User/Fonts/font12.o ./Core/User/Fonts/font12.su ./Core/User/Fonts/font16.d ./Core/User/Fonts/font16.o ./Core/User/Fonts/font16.su ./Core/User/Fonts/font20.d ./Core/User/Fonts/font20.o ./Core/User/Fonts/font20.su ./Core/User/Fonts/font24.d ./Core/User/Fonts/font24.o ./Core/User/Fonts/font24.su ./Core/User/Fonts/font32.d ./Core/User/Fonts/font32.o ./Core/User/Fonts/font32.su ./Core/User/Fonts/font48.d ./Core/User/Fonts/font48.o ./Core/User/Fonts/font48.su ./Core/User/Fonts/font8.d ./Core/User/Fonts/font8.o ./Core/User/Fonts/font8.su

.PHONY: clean-Core-2f-User-2f-Fonts

