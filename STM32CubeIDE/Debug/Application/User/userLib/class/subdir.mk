################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/User/userLib/class/classTruck.cpp 

OBJS += \
./Application/User/userLib/class/classTruck.o 

CPP_DEPS += \
./Application/User/userLib/class/classTruck.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/userLib/class/%.o Application/User/userLib/class/%.su Application/User/userLib/class/%.cyclo: ../Application/User/userLib/class/%.cpp Application/User/userLib/class/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DDEBUG -DSTM32H735xx -c -I../../Core/Inc -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/globals" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/dataClass/Abstract" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/appClass/uartTaskOperator.hpp" -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H735G-DK -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/Core" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/App" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/modelClasses" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/appClass" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/dataClass" -include"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/utilities.hpp" -include"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/appClass/uartTaskOperator.hpp" -include"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/App/app_user.h" -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -Wfatal-errors -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-userLib-2f-class

clean-Application-2f-User-2f-userLib-2f-class:
	-$(RM) ./Application/User/userLib/class/classTruck.cyclo ./Application/User/userLib/class/classTruck.d ./Application/User/userLib/class/classTruck.o ./Application/User/userLib/class/classTruck.su

.PHONY: clean-Application-2f-User-2f-userLib-2f-class

