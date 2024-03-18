/*
 * uartTaskOperator.cpp
 *
 *  Created on: Jun 29, 2023
 *      Authors: KaDzejoo, Cris
 */

#include <class/appClass/uartTaskOperator.hpp>
#include <class/appClass/ioTaskOperator.hpp>
#include <integrityManager.hpp>
#include <MessageEncoder.hpp>
#include "cmsis_os.h"
#include "main.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_gpio.h"
#include "NotificationFactory.hpp"
#include "stm32h7xx_hal_uart.h"
#include "stm32h7xx_hal_def.h"



extern NotificationFactory notificationFactory;
extern UART_HandleTypeDef huart7;
extern UART_HandleTypeDef huart5;
extern InputOutputModel controllerState;
extern MessageEncoder encoder;
extern MessageFrame frame;

//uint8_t send[30]={0x7E,0x00,0x0A,0x01,0x00,0x00,0x20,0x00,0x48,0x65,0x6C,0x6C,0x6F,0xE9};
//uint8_t send[12]={0x7E, 0x00, 0x08, 0x01, 0x01, 0x00, 0x20, 0x00, 0x01, 0x02, 0x03, 0xD7};
//uint8_t send[22]={0x7E, 0x00, 0x7D, 0x31, 0x01, 0x00, 0x00, 0x20, 0x00, 0x44, 0x01, 0x10, 0x00, 0x02, 0x00, 0x01, 0x00, 0x32, 0x32, 0x32, 0x00, 0xF4};
uint8_t send[20] = { 0x7E, 0x00, 0x10, 0x01, 0x00, 0x00, 0x20, 0x00, 0x44, 0xD0, 0x18, 0xA9, 0xA9, 0xC2, 0x32, 0x32, 0x01, 0x32, 0x32, 0xD5};
uint8_t value;






uartTaskOperator::uartTaskOperator()
{


}



void uartTaskOperator::taskEntry(){

	for (;;)
	   {
		//Start receiving on IT routine
		HAL_UART_Receive_IT(&huart7, &value, 1);

		//Set received frame
		//encoder.frameRecv.setRecvArray(recieved, 60);


		// encode message into array
		encoder.encodeStateToMessage();

		//transmit array via UART7 / UART5
		HAL_UART_Transmit_IT(&huart7,encoder.getBinaryArr(),60);
		HAL_UART_Transmit_IT(&huart5,encoder.getBinaryArr(),60);



		osDelay(settingsM.uartTimeDelay);
	   }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//TODO getting value out of xbee
	HAL_UART_Receive_IT(&huart7, &value, 1);
	int i = 0;
	//controllerState.recieved[i++]=value;

	if(i==14)
	{
		i=0;
	}
	return ;
}

/*
int16_t AddToUSART_XBeeQueue(uint8_t * binaryArray,uint8_t len)
{
    // dodoaj tablice bajt w o dlugosci len, reprezentowana przez wskaznik binaryArray, do kolejki wysylkowej
//    unsigned char znak;


//	dodawanieDoKolejkiOUT=1;
    uint16_t i;
    for(i=0; i<len; i++)
    {
        if (! isFullOUT(pBufferOut))  // jezeli bufor sie przepelni to nalezy czekaz na wolne miejsce  (while(buffer_full());)
        {

            writeBufferOUT(pBufferOut,binaryArray[i]);
        }
        else
        {
            while(isFullOUT(pBufferOut));

            writeBufferOUT(pBufferOut,binaryArray[i]);

            //printf("\nBUFFER IS FULL!");
//			return -128;  // error: XBee USART BUFFER FULL
        }
    }
    //	dodawanieDoKolejkiOUT=0;
    // jezeli nie ma wysylania

    if(XBEE_USART->SR & 0x00000040)
    {
        // wyslij oczekujacy znak z bufora
        if( ! isEmptyOUT(pBufferOut))
        {
            USART_ITConfig(XBEE_USART, USART_IT_TXE, ENABLE);
            //znak = pull_char();
            //USART_SendData(USART2, znak);
        }
    }
    return 0;
}

 */
