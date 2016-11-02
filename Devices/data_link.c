#include "data_link.h"
#include "string.h"
#include "stm32f4xx_hal.h"
extern UART_HandleTypeDef huart1;
#define TX_BUF_SIZE 29
unsigned short crc16(void* data, unsigned short cnt);
unsigned char tx_buffer[TX_BUF_SIZE];

void data_link_init(void)
{
	
}

void send_buffer(void *data, unsigned short len)
{
	unsigned char protocol_head[3]={'>','*','>'};
	unsigned char protocol_last[3]={'<','#','<'};
	unsigned char packetdescriptor='c';
	short crc_result = crc16(data,len);
	memcpy(tx_buffer,protocol_head,3);
	memcpy(tx_buffer+3,&len,2);
	memcpy(tx_buffer+5,&packetdescriptor, 1);
	memcpy(tx_buffer+6,data,18);
	memcpy(tx_buffer+24,&crc_result,2);
	memcpy(tx_buffer+26,protocol_last,3);
	HAL_UART_Transmit_DMA(&huart1, tx_buffer, TX_BUF_SIZE);
}
unsigned short crc_update (unsigned short crc, unsigned char data)
{
    data ^= (crc & 0xff);
    data ^= data << 4;
    return ((((unsigned short )data << 8) | ((crc>>8)&0xff)) ^ (unsigned char )(data >> 4)
         ^ ((unsigned short )data << 3));
}
unsigned short crc16(void* data, unsigned short cnt)
{
    unsigned short crc=0xff;
    unsigned char * ptr=(unsigned char *) data;
    int i;
    for (i=0;i<cnt;i++){
        crc=crc_update(crc,*ptr);
        ptr++;
    }
    return crc;
}
