################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/userLib/App/app_user.c 

C_DEPS += \
./Application/User/userLib/App/app_user.d 

OBJS += \
./Application/User/userLib/App/app_user.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/userLib/App/%.o Application/User/userLib/App/%.su Application/User/userLib/App/%.cyclo: ../Application/User/userLib/App/%.c Application/User/userLib/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DSTM32H735xx -c -I../../Core/Inc -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H735G-DK -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/Core" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/App" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-userLib-2f-App

clean-Application-2f-User-2f-userLib-2f-App:
	-$(RM) ./Application/User/userLib/App/app_user.cyclo ./Application/User/userLib/App/app_user.d ./Application/User/userLib/App/app_user.o ./Application/User/userLib/App/app_user.su

.PHONY: clean-Application-2f-User-2f-userLib-2f-App

