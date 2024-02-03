################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/Examples/EPD_1in54b_test.c \
../Core/User/Examples/EPD_2in7b_test.c \
../Core/User/Examples/ImageData.c \
../Core/User/Examples/ImageData2.c 

OBJS += \
./Core/User/Examples/EPD_1in54b_test.o \
./Core/User/Examples/EPD_2in7b_test.o \
./Core/User/Examples/ImageData.o \
./Core/User/Examples/ImageData2.o 

C_DEPS += \
./Core/User/Examples/EPD_1in54b_test.d \
./Core/User/Examples/EPD_2in7b_test.d \
./Core/User/Examples/ImageData.d \
./Core/User/Examples/ImageData2.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/Examples/%.o Core/User/Examples/%.su: ../Core/User/Examples/%.c Core/User/Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User-2f-Examples

clean-Core-2f-User-2f-Examples:
	-$(RM) ./Core/User/Examples/EPD_1in54b_test.d ./Core/User/Examples/EPD_1in54b_test.o ./Core/User/Examples/EPD_1in54b_test.su ./Core/User/Examples/EPD_2in7b_test.d ./Core/User/Examples/EPD_2in7b_test.o ./Core/User/Examples/EPD_2in7b_test.su ./Core/User/Examples/ImageData.d ./Core/User/Examples/ImageData.o ./Core/User/Examples/ImageData.su ./Core/User/Examples/ImageData2.d ./Core/User/Examples/ImageData2.o ./Core/User/Examples/ImageData2.su

.PHONY: clean-Core-2f-User-2f-Examples

