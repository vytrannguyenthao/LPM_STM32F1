################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc_dma.c \
../Src/data.c \
../Src/digital_clock.c \
../Src/font8x8.c \
../Src/gpio.c \
../Src/gpio_exti.c \
../Src/main.c \
../Src/mode.c \
../Src/rcc_config.c \
../Src/rtc.c \
../Src/rtc_app.c \
../Src/sharp96.c \
../Src/spi.c \
../Src/standby.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim.c 

OBJS += \
./Src/adc_dma.o \
./Src/data.o \
./Src/digital_clock.o \
./Src/font8x8.o \
./Src/gpio.o \
./Src/gpio_exti.o \
./Src/main.o \
./Src/mode.o \
./Src/rcc_config.o \
./Src/rtc.o \
./Src/rtc_app.o \
./Src/sharp96.o \
./Src/spi.o \
./Src/standby.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim.o 

C_DEPS += \
./Src/adc_dma.d \
./Src/data.d \
./Src/digital_clock.d \
./Src/font8x8.d \
./Src/gpio.d \
./Src/gpio_exti.d \
./Src/main.d \
./Src/mode.d \
./Src/rcc_config.d \
./Src/rtc.d \
./Src/rtc_app.d \
./Src/sharp96.d \
./Src/spi.d \
./Src/standby.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F103xB -c -I../Inc -I"D:/HOC_TAP/02_PIF/PIF_Courses/EmbeddedC/udemy_course/STM32BareMetal-Projects/00_test/chip_headers/CMSIS/Include" -I"D:/HOC_TAP/02_PIF/PIF_Courses/EmbeddedC/udemy_course/STM32BareMetal-Projects/00_test/chip_headers/CMSIS/Device/ST/STM32F1xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc_dma.d ./Src/adc_dma.o ./Src/adc_dma.su ./Src/data.d ./Src/data.o ./Src/data.su ./Src/digital_clock.d ./Src/digital_clock.o ./Src/digital_clock.su ./Src/font8x8.d ./Src/font8x8.o ./Src/font8x8.su ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/gpio_exti.d ./Src/gpio_exti.o ./Src/gpio_exti.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/mode.d ./Src/mode.o ./Src/mode.su ./Src/rcc_config.d ./Src/rcc_config.o ./Src/rcc_config.su ./Src/rtc.d ./Src/rtc.o ./Src/rtc.su ./Src/rtc_app.d ./Src/rtc_app.o ./Src/rtc_app.su ./Src/sharp96.d ./Src/sharp96.o ./Src/sharp96.su ./Src/spi.d ./Src/spi.o ./Src/spi.su ./Src/standby.d ./Src/standby.o ./Src/standby.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tim.d ./Src/tim.o ./Src/tim.su

.PHONY: clean-Src

