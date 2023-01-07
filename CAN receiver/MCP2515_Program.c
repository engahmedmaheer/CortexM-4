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

void MCP2515_VidSetRollover(u8 value)
{
	MCP2515_VidChangeBits(RXB0CTRL, 1<<BUKT, value<<BUKT);
}

void MCP2515_VidSetMask(u8 maskAddress, u32 maskValue, u8 extended)
{
	SPI_VidChipSelect(1);
	SPI_U8MasterTransmit(INST_WRITE);
	SPI_U8MasterTransmit(maskAddress);

	if(extended)
	{
		// extended address
		SPI_U8MasterTransmit((u8) (maskValue >> 3));
		SPI_U8MasterTransmit((u8) (maskValue << 5) | (1<<3) | (u8) (maskValue >> 27));
		SPI_U8MasterTransmit((u8) (maskValue >> 19));
		SPI_U8MasterTransmit((u8) (maskValue >> 11));
	}
	else
	{
		// standard address
		SPI_U8MasterTransmit((u8) (maskValue >> 3));
		SPI_U8MasterTransmit((u8) (maskValue << 5));
	}
	SPI_VidChipSelect(0);
}

void MCP2515_VidReceiveInit(void)
{
	SPI_VidMasterInit();
	MCP2515_VidReset();

//	// enter configuration mode and enable CLKOUT with no prescaler
	MCP2515_VidWriteRegister(CANCTRL, 0x84);
	while((MCP2515_U8ReadRegister(CANSTAT)>>5) != MCP2515_MODE_CONFG);
//	// to run at 250KHz bitrate using 8MHz osc
	MCP2515_VidSetBitTiming((2<<6), (1<<7)|(6<<3)|(1), (5));
//	MCP2515_VidSetBitTiming(0, 0xAC, 0x03);
	// accept all messages
	MCP2515_VidSetMask(RXM0SIDH, 0x00000000, 1);
	MCP2515_VidSetMask(RXM1SIDH, 0x00000000, 1);
	MCP2515_VidSetRollover(1);

	MCP2515_VidWriteRegister(CANINTE, 1<<RX0IE);

	MCP2515_VidSetMode(MCP2515_MODE_NORMAL);
}

u8 readBuffer[14];
void MCP2515_VidReceiveCANmsg(void)
{
	SPI_VidChipSelect(1);

	SPI_U8MasterTransmit(INST_READ);
	SPI_U8MasterTransmit(RXB0CTRL);

	for(u8 i=0; i<14; i++)
	{
		readBuffer[i] = SPI_U8MasterTransmit(0);
	}

	SPI_VidChipSelect(0);

	MCP2515_VidWriteRegister(CANINTF, 0);
}