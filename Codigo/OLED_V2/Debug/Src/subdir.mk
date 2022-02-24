################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Oled.c \
../Src/STMiCON.c \
../Src/USART.c \
../Src/delay.c \
../Src/gui.c \
../Src/main.c \
../Src/mono.c \
../Src/pajaro.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c \
../Src/test.c 

OBJS += \
./Src/Oled.o \
./Src/STMiCON.o \
./Src/USART.o \
./Src/delay.o \
./Src/gui.o \
./Src/main.o \
./Src/mono.o \
./Src/pajaro.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o \
./Src/test.o 

C_DEPS += \
./Src/Oled.d \
./Src/STMiCON.d \
./Src/USART.d \
./Src/delay.d \
./Src/gui.d \
./Src/main.d \
./Src/mono.d \
./Src/pajaro.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d \
./Src/test.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -DSTM32F401xE -c -I../Inc -I"C:/Users/Lenovo/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.2/Drivers/CMSIS/Include" -I"C:/Users/Lenovo/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Oled.d ./Src/Oled.o ./Src/STMiCON.d ./Src/STMiCON.o ./Src/USART.d ./Src/USART.o ./Src/delay.d ./Src/delay.o ./Src/gui.d ./Src/gui.o ./Src/main.d ./Src/main.o ./Src/mono.d ./Src/mono.o ./Src/pajaro.d ./Src/pajaro.o ./Src/stm32f4xx_it.d ./Src/stm32f4xx_it.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/test.d ./Src/test.o

.PHONY: clean-Src

