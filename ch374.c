#include "ch374.h"

#define CH374_MAX_TRANSFER 20

static uint8_t ch374_transbuf[CH374_MAX_TRANSFER];


int ch374_readBytes(uint8_t addr, uint8_t *buffer, uint8_t rx_len)
{
    ch374_transbuf[0] = addr;
    ch374_transbuf[1] = 0xc0;
    
    digitalWrite(CH374_CS, LOW);
    spi_transfer(ch374_transbuf, 2, ch374_transbuf, rx_len + 2);
    digitalWrite(CH374_CS, HIGH);
	memcpy(buffer, ch374_transbuf + 2, rx_len);
    return true;
}

int ch374_writeBytes(uint8_t addr, uint8_t *buffer, uint16_t tx_len)
{
    ch374_transbuf[0] = addr;
    ch374_transbuf[1] = 0x80;
    
    memcpy(ch374_transbuf + 2, buffer, tx_len);
    
    digitalWrite(CH374_CS, LOW);
    spi_transfer(ch374_transbuf, tx_len + 2, NULL, 0);
    digitalWrite(CH374_CS, HIGH);
		
    return true;
}

void ch374_begin(void)
{

    spi_init();
    pinMode(CH374_CS, OUTPUT);
    
    uint8_t regVal;
    
    regVal = 0x02;
    ch374_writeBytes(CH374_REG_SYS_AUX, &regVal, 1);
    
    ch374_readBytes(CH374_REG_SYS_INFO, &regVal, 1);
    Debug("REG_SYS_INFO %x", regVal);
    
    regVal = 0x06; //12MHz 3.3V
    ch374_writeBytes(CH374_REG_SYS_CTRL, &regVal, 1);
    
    regVal = 0x07; //start device
    ch374_writeBytes(CH374_REG_USB_SETUP, &regVal, 1);
    
    ch374_readBytes(CH374_REG_USB_ADDR, &regVal, 1);
    Debug("REG_USB_ADDR %x", regVal);
    
}
