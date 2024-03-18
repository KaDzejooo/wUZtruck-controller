################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/User/userLib/class/factories/ConnectionManager.cpp \
../Application/User/userLib/class/factories/KeyboardDecoder.cpp \
../Application/User/userLib/class/factories/MessageEncoder.cpp \
../Application/User/userLib/class/factories/NotificationFactory.cpp \
../Application/User/userLib/class/factories/ThemeFactory.cpp \
../Application/User/userLib/class/factories/VehicleFactory.cpp 

OBJS += \
./Application/User/userLib/class/factories/ConnectionManager.o \
./Application/User/userLib/class/factories/KeyboardDecoder.o \
./Application/User/userLib/class/factories/MessageEncoder.o \
./Application/User/userLib/class/factories/NotificationFactory.o \
./Application/User/userLib/class/factories/ThemeFactory.o \
./Application/User/userLib/class/factories/VehicleFactory.o 

CPP_DEPS += \
./Application/User/userLib/class/factories/ConnectionManager.d \
./Application/User/userLib/class/factories/KeyboardDecoder.d \
./Application/User/userLib/class/factories/MessageEncoder.d \
./Application/User/userLib/class/factories/NotificationFactory.d \
./Application/User/userLib/class/factories/ThemeFactory.d \
./Application/User/userLib/class/factories/VehicleFactory.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/userLib/class/factories/%.o Application/User/userLib/class/factories/%.su Application/User/userLib/class/factories/%.cyclo: ../Application/User/userLib/class/factories/%.cpp Application/User/userLib/class/factories/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=24 -DDEBUG -DSTM32H735xx -c -I../../Core/Inc -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/dataClass/Abstract" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/globals" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/dataClass" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/appClass/uartTaskOperator.hpp" -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/STM32H735G-DK -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/Core" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/App" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/modelClasses" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/appClass" -I"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/dataClass" -include"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/utilities.hpp" -include"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/class/appClass/uartTaskOperator.hpp" -include"C:/Users/oem/Desktop/repositories/wUZtruck-controllerApp/STM32CubeIDE/Application/User/userLib/App/app_user.h" -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -Wfatal-errors -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-userLib-2f-class-2f-factories

clean-Application-2f-User-2f-userLib-2f-class-2f-factories:
	-$(RM) ./Application/User/userLib/class/factories/ConnectionManager.cyclo ./Application/User/userLib/class/factories/ConnectionManager.d ./Application/User/userLib/class/factories/ConnectionManager.o ./Application/User/userLib/class/factories/ConnectionManager.su ./Application/User/userLib/class/factories/KeyboardDecoder.cyclo ./Application/User/userLib/class/factories/KeyboardDecoder.d ./Application/User/userLib/class/factories/KeyboardDecoder.o ./Application/User/userLib/class/factories/KeyboardDecoder.su ./Application/User/userLib/class/factories/MessageEncoder.cyclo ./Application/User/userLib/class/factories/MessageEncoder.d ./Application/User/userLib/class/factories/MessageEncoder.o ./Application/User/userLib/class/factories/MessageEncoder.su ./Application/User/userLib/class/factories/NotificationFactory.cyclo ./Application/User/userLib/class/factories/NotificationFactory.d ./Application/User/userLib/class/factories/NotificationFactory.o ./Application/User/userLib/class/factories/NotificationFactory.su ./Application/User/userLib/class/factories/ThemeFactory.cyclo ./Application/User/userLib/class/factories/ThemeFactory.d ./Application/User/userLib/class/factories/ThemeFactory.o ./Application/User/userLib/class/factories/ThemeFactory.su ./Application/User/userLib/class/factories/VehicleFactory.cyclo ./Application/User/userLib/class/factories/VehicleFactory.d ./Application/User/userLib/class/factories/VehicleFactory.o ./Application/User/userLib/class/factories/VehicleFactory.su

.PHONY: clean-Application-2f-User-2f-userLib-2f-class-2f-factories

