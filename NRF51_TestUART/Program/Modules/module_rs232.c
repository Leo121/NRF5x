/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "nrf51_uart.h"
#include "module_rs232.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define UARTx_TXD_PIN       9
#define UARTx_RXD_PIN       11

#define UARTx_BAUDRATE      UART_BAUDRATE_BAUDRATE_Baud115200
#define UARTx_PARITY        UART_CONFIG_PARITY_Excluded
#define UARTx_HARDWARECTRL  UART_CONFIG_HWFC_Disabled
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_Config
**功能 : RS232 配置
**輸入 : None
**輸出 : None
**使用 : RS232_Config();
**====================================================================================================*/
/*====================================================================================================*/
void RS232_Config( void )
{
  UART_InitTypeDef UART_InitStruct;

  UART_InitStruct.UART_PinTXD              = UARTx_TXD_PIN;
  UART_InitStruct.UART_PinRXD              = UARTx_RXD_PIN;
  UART_InitStruct.UART_BaudRate            = UARTx_BAUDRATE;
  UART_InitStruct.UART_Parity              = UARTx_PARITY;
  UART_InitStruct.UART_HardwareFlowControl = UARTx_HARDWARECTRL;
  UART_Init(&UART_InitStruct);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendByte
**功能 : 發送 1Byte 資料
**輸入 : SendByte
**輸出 : None
**使用 : RS232_SendByte('A');
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendByte( uint8_t SendByte )
{
  UART_SendByte(SendByte);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendData
**功能 : 發送資料
**輸入 : *SendData, DataLen
**輸出 : None
**使用 : RS232_SendData(SendData, DataLen);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendData( uint8_t *SendData, uint16_t DataLen )
{
  UART_SendData(SendData, DataLen);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendNum
**功能 : 將數值轉字串發送
**輸入 : Type, NumLen, SendData
**輸出 : None
**使用 : RS232_SendNum(Type_O, 6, 1024);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendNum( StrType Type, uint8_t NumLen, int32_t SendData )
{
  uint8_t TrData[32] = {0};
  uint8_t *pWord = TrData;

  Str_NumToChar(Type, NumLen, TrData, SendData);

  while(*pWord != '\0') {
    UART_SendByte(*pWord);
    pWord++;
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendStr
**功能 : 發送字串
**輸入 : *pWord
**輸出 : None
**使用 : RS232_SendStr((uint8_t*)"Hellow World!");
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendStr( uint8_t *pWord )
{
  while(*pWord != '\0') {
    UART_SendByte(*pWord);
    pWord++;
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvByte
**功能 : 接收 1Byte 資料
**輸入 : *RecvData
**輸出 : None
**使用 : RS232_RecvByte(RecvData);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvByte( uint8_t *RecvData )
{
  *RecvData = UART_RecvByte();
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvByteWTO
**功能 : 接收資料
**輸入 : *RecvData
**輸出 : Statea
**使用 : State = RS232_RecvByteWTO(RecvData, Timeout_ms);
**====================================================================================================*/
/*====================================================================================================*/
uint8_t RS232_RecvByteWTO( uint8_t *RecvData, int32_t Timeout_ms )
{
  return UART_RecvByteWTO(RecvData, Timeout_ms);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvData
**功能 : 接收資料
**輸入 : *RecvData, DataLen
**輸出 : None
**使用 : RS232_RecvData(RecvData, DataLen);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvData( uint8_t *RecvData, uint16_t DataLen )
{
  UART_RecvData(RecvData, DataLen);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvDataWTO
**功能 : 接收資料
**輸入 : *RecvData, DataLen, Timeout_ms
**輸出 : State
**使用 : State = RS232_RecvDataWTO(RecvData, DataLen, Timeout_ms);
**====================================================================================================*/
/*====================================================================================================*/
uint8_t RS232_RecvDataWTO( uint8_t *RecvData, uint16_t DataLen, int32_t Timeout_ms )
{
  return UART_RecvDataWTO(RecvData, DataLen, Timeout_ms);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvStr
**功能 : 接收字串
**輸入 : *pWord
**輸出 : None
**使用 : RS232_RecvStr(RecvStirng);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvStr( uint8_t *pWord )
{
  do {
    *pWord = UART_RecvByte();
    pWord++;
  } while(*(pWord-1) != '\0');
  *pWord = '\0';
}
/*====================================================================================================*/
/*====================================================================================================*/
