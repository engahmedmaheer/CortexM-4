/*
 *
 * MCP2515_Program.c
 * Created on:
 * Version: 02
 * Author: Eng. Ahmed Maher
 * 
 */
#include "STD_TYPE.h"

#include "SPI_Interface.h"
#include "MCP2515_Interface.h"
#include "MCP2515_Private.h"


u8 MCP2515_U8ReadRegister(u8 address)
{
	u8 readValue;
	SPI_VidChipSelect(1);
	SPI_U8MasterTransmit(INST_READ);
	SPI_U8MasterTransmit(address);
	readValue = SPI_U8MasterTransmit(0);
	SPI_VidChipSelect(0);

	return readValue;
}

void MCP2515_VidWriteRegister(u8 address, u8 value)
{
	SPI_VidChipSelect(1);
	SPI_U8MasterTransmit(INST_WRITE);
	SPI_U8MasterTransmit(address);
	SPI_U8MasterTransmit(value);
	SPI_VidChipSelect(0);
}

void MCP2515_VidSetBitTiming(u8 cnf1Value, u8 cnf2Value, u8 cnf3Value)
{
	MCP2515_VidWriteRegister(CNF1, cnf1Value);
	MCP2515_VidWriteRegister(CNF2, cnf2Value);
	MCP2515_VidWriteRegister(CNF3, cnf3Value);
}

void MCP2515_VidReset()
{
	SPI_VidChipSelect(1);
	SPI_U8MasterTransmit(INST_RESET);
	SPI_VidChipSelect(0);
}

void MCP2515_VidChangeBits(u8 RegAddress, u8 Mask, u8 Value)
{
	SPI_VidChipSelect(1);
	SPI_U8MasterTransmit(INST_BIT_MODIFY);
	SPI_U8MasterTransmit(RegAddress);
	SPI_U8MasterTransmit(Mask);
	SPI_U8MasterTransmit(Value);
	SPI_VidChipSelect(0);
}

void MCP2515_VidSetMode(u8 mode)
{

	MCP2515_VidChangeBits(CANCTRL, 0xE0, mode << 5);
	while((MCP2515_U8ReadRegister(CANSTAT)>>5) != mode );
}

void MCP2515_VidInit(void)
{
	SPI_VidMasterInit();
	MCP2515_VidReset();

//	// enter configuration mode and enable CLKOUT with no prescaler
	MCP2515_VidWriteRegister(CANCTRL, 0x84);
	while((MCP2515_U8ReadRegister(CANSTAT)>>5) != MCP2515_MODE_CONFG);
//	// to run at 250KHz bitrate using 8MHz osc
	MCP2515_VidSetBitTiming((2<<6), (1<<7)|(6<<3)|(1), (5));

	MCP2515_VidSetMode(MCP2515_MODE_NORMAL);
}


void MCP2515_VidSendCANmsg(u8 bufIdx, u32 msgID, u8 * data,u8 properties)
{
	SPI_VidChipSelect(1);
	/* Send header and address */
	SPI_U8MasterTransmit(INST_WRITE);
	SPI_U8MasterTransmit(TXB0CTRL);
    
	/* Setup message priority */
	SPI_U8MasterTransmit(properties >> 6);
	/* Setup standard or extended identifier */
		SPI_U8MasterTransmit((u8)(msgID>>3));
		SPI_U8MasterTransmit((u8)(msgID<<5));
		SPI_U8MasterTransmit(0);
		SPI_U8MasterTransmit(0);
        
	/* Setup message length and RTR bit */
	SPI_U8MasterTransmit((properties & 0x0F);
    
	/* Store the message into the buffer */
	for(u8 i = 0; i < (properties & 0x0F); i++)
		SPI_U8MasterTransmit(data[i]);
    
	/* Release the bus */
	SPI_VidChipSelect(0);
    
	/* Send request to send */
	SPI_VidChipSelect(1);
	SPI_U8MasterTransmit(INST_RTS_TXB0);
	SPI_VidChipSelect(0);
	}
