#ifndef __CH374_H__
#define __CH374_H__

#include "transfer_handler.h"

#define CH374_REG_SYS_AUX     0x01

#define CH374_REG_SYS_INFO    0x04
#define CH374_REG_SYS_CTRL    0x05
#define CH374_REG_USB_SETUP   0x06
#define CH374_REG_INTER_EN    0x07
#define CH374_REG_USB_ADDR    0x08
#define CH374_REG_INTER_FLAG  0x09
#define CH374_REG_USB_STATUS  0x0a
#define CH374_REG_USB_LENGTH  0x0b
#define CH374_REG_USB_ENDP0   0x0c
#define CH374_REG_USB_ENDP1   0x0d
#define CH374_REG_USB_ENDP2   0x0e


#define CH374_RAM_ENDP0_TRAN  0x20  //to 0x27 8 bytes
#define CH374_RAM_ENDP0_RECV  0x28  //to 0x2f 8 bytes
#define CH374_RAM_ENDP0_BUF   0x20  //to 0x2f 16 bytes
#define CH374_RAM_ENDP1_TRAN  0x30  //to 0x37 8 bytes
#define CH374_RAM_ENDP1_RECV  0x38  //to 0x3f 8 bytes
#define CH374_RAM_ENDP2_TRAN  0x40  //to 0x7f
#define CH374_RAM_ENDP2_RECV  0xc0  //to 0xff
#define CH374_RAM_ENDP2_EXCH  0x80  //to 0xbf


//HOST SPECIFIC
#define CH374_REG_HUB_SETUP   0x02
#define CH374_REG_HUB_CTRL    0x03
#define CH374_REG_USB_H_TOKEN 0x0d
#define CH374_REG_USB_H_CTRL  0x0e
#define CH374_RAM_HOST_TRAN   0x40  //to 0x7f
#define CH374_RAM_HOST_RECV   0xc0  //to 0xff
#define CH374_RAM_HOST_EXCH   0x80  //to 0xbf

int ch374_readBytes(uint8_t addr, uint8_t *buffer, uint8_t rx_len);
int ch374_writeBytes(uint8_t addr, uint8_t *buffer, uint16_t tx_len);
void ch374_begin(void);

#endif