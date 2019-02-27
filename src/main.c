#include <stdio.h>

#include "stm32_conf.h"

#include "SWD_host.h"
#include "SWD_flash.h"

#include "algo/STM32F10x_128.c"
uint32_t Flash_Page_Size = 1024;
uint32_t Flash_Start_Addr = 0x08000000;

extern uint8_t STM32F1_demo_code[3604];

uint8_t buff[1024] = {0};

void SerialInit(void);

int main(void)
{		
	SerialInit();
	
	swd_init_debug();
	
	target_flash_init(Flash_Start_Addr);
	
	for(uint32_t addr = 0; addr < sizeof(STM32F1_demo_code); addr += 1024)
	{
		target_flash_erase_sector(0x08000000+addr);
	}
	
	for(uint32_t addr = 0; addr < sizeof(STM32F1_demo_code); addr += 1024)
	{
		swd_read_memory(0x08000000 + addr, buff, 1024);
		for(uint32_t i = 0; i < 1024; i++) printf("%02X ", buff[i]);
		printf("\r\n\r\n\r\n");
	}
	
	for(uint32_t addr = 0; addr < sizeof(STM32F1_demo_code); addr += 1024)
	{
		target_flash_program_page(0x08000000+addr, &STM32F1_demo_code[addr], 1024);
	}
	
	for(uint32_t addr = 0; addr < sizeof(STM32F1_demo_code); addr += 1024)
	{
		swd_read_memory(0x08000000 + addr, buff, 1024);
		for(uint32_t i = 0; i < 1024; i++) printf("%02X ", buff[i]);
		printf("\r\n\r\n\r\n");
	}
	
	swd_set_target_state_hw(RUN);
	
	while(1)
	{
		
	}
}


uint8_t STM32F1_demo_code[3604] = {
	0x30, 0x04, 0x00, 0x20, 0xF9, 0x03, 0x00, 0x08, 0x01, 0x04, 0x00, 0x08, 0x03, 0x04, 0x00, 0x08, 
	0x05, 0x04, 0x00, 0x08, 0x07, 0x04, 0x00, 0x08, 0x09, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x04, 0x00, 0x08, 
	0x0D, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x04, 0x00, 0x08, 0x11, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 0x13, 0x04, 0x00, 0x08, 
	0xDF, 0xF8, 0x0C, 0xD0, 0x00, 0xF0, 0x06, 0xFE, 0x00, 0x48, 0x00, 0x47, 0xA9, 0x01, 0x00, 0x08, 
	0x30, 0x04, 0x00, 0x20, 0x30, 0xB5, 0x87, 0xB0, 0x01, 0x21, 0x04, 0x20, 0x00, 0xF0, 0xD5, 0xFB, 
	0x3D, 0x4C, 0xA0, 0x68, 0x06, 0x90, 0x3D, 0x4D, 0x06, 0xA9, 0x28, 0x46, 0x00, 0xF0, 0xC7, 0xF9, 
	0xE1, 0x68, 0x05, 0x91, 0x05, 0xA9, 0x28, 0x46, 0x00, 0xF0, 0xC1, 0xF9, 0x01, 0x21, 0x88, 0x03, 
	0x00, 0xF0, 0xC3, 0xFB, 0x4F, 0xF4, 0x61, 0x40, 0x01, 0x90, 0x00, 0x20, 0xAD, 0xF8, 0x08, 0x00, 
	0xAD, 0xF8, 0x0A, 0x00, 0xAD, 0xF8, 0x0C, 0x00, 0xAD, 0xF8, 0x10, 0x00, 0x0C, 0x20, 0xAD, 0xF8, 
	0x0E, 0x00, 0x2F, 0x4C, 0x01, 0xA9, 0x20, 0x46, 0x00, 0xF0, 0x4E, 0xFC, 0x01, 0x21, 0x20, 0x46, 
	0x00, 0xF0, 0xC5, 0xFC, 0x07, 0xB0, 0x30, 0xBD, 0x1C, 0xB5, 0xFF, 0xF7, 0xCB, 0xFF, 0x01, 0x21, 
	0x10, 0x20, 0x00, 0xF0, 0xA2, 0xFB, 0x24, 0x4C, 0x20, 0x68, 0x01, 0x90, 0x25, 0x4D, 0x01, 0xA9, 
	0x28, 0x46, 0x00, 0xF0, 0x94, 0xF9, 0x01, 0x21, 0x04, 0x20, 0x00, 0xF0, 0x96, 0xFB, 0x61, 0x68, 
	0x00, 0x91, 0x1E, 0x4F, 0x69, 0x46, 0x38, 0x46, 0x00, 0xF0, 0x89, 0xF9, 0x1E, 0x4E, 0x4F, 0xF4, 
	0x00, 0x48, 0x0A, 0x24, 0x01, 0x21, 0x28, 0x46, 0x00, 0xF0, 0xE6, 0xF9, 0x78, 0xB1, 0x00, 0x22, 
	0x01, 0x21, 0x28, 0x46, 0x00, 0xF0, 0xEE, 0xF9, 0x41, 0x46, 0x38, 0x46, 0x00, 0xF0, 0xD2, 0xF9, 
	0x38, 0xB1, 0x16, 0xA0, 0x00, 0xF0, 0xB0, 0xFD, 0x00, 0x22, 0x33, 0x68, 0x07, 0xE0, 0x01, 0x22, 
	0xEE, 0xE7, 0x17, 0xA0, 0x00, 0xF0, 0xA8, 0xFD, 0xF6, 0xE7, 0x00, 0xBF, 0x52, 0x1C, 0xB3, 0xFB, 
	0xF4, 0xF0, 0x90, 0x42, 0xDE, 0xD9, 0xF8, 0xE7, 0x70, 0xB5, 0x04, 0x46, 0x08, 0x4D, 0x80, 0x21, 
	0x28, 0x46, 0x00, 0xF0, 0x4A, 0xFD, 0x00, 0x28, 0xF9, 0xD0, 0xA1, 0xB2, 0x28, 0x46, 0x00, 0xF0, 
	0xD7, 0xFC, 0x20, 0x46, 0x70, 0xBD, 0x00, 0x00, 0xB8, 0x0D, 0x00, 0x08, 0x00, 0x08, 0x01, 0x40, 
	0x00, 0x38, 0x01, 0x40, 0x00, 0x10, 0x01, 0x40, 0x00, 0x00, 0x00, 0x20, 0x48, 0x69, 0x20, 0x46, 
	0x72, 0x6F, 0x6D, 0x20, 0x58, 0x49, 0x56, 0x4E, 0x31, 0x39, 0x38, 0x37, 0x21, 0x0D, 0x0A, 0x00, 
	0x0D, 0x0A, 0x4B, 0x65, 0x79, 0x20, 0x50, 0x72, 0x65, 0x73, 0x73, 0x65, 0x64, 0x21, 0x0D, 0x0A, 
	0x0D, 0x0A, 0x00, 0x00, 0x0C, 0xB5, 0x00, 0x22, 0x01, 0x92, 0x00, 0x92, 0x52, 0x48, 0x01, 0x68, 
	0x41, 0xF4, 0x80, 0x31, 0x01, 0x60, 0x4F, 0xF4, 0xA0, 0x63, 0x01, 0x68, 0x01, 0xF4, 0x00, 0x31, 
	0x00, 0x91, 0x01, 0x99, 0x49, 0x1C, 0x01, 0x91, 0x00, 0x99, 0x11, 0xB9, 0x01, 0x99, 0x99, 0x42, 
	0xF3, 0xD1, 0x01, 0x68, 0x89, 0x03, 0x02, 0xD5, 0x01, 0x21, 0x00, 0x91, 0x00, 0xE0, 0x00, 0x92, 
	0x00, 0x99, 0x01, 0x29, 0x30, 0xD1, 0x45, 0x49, 0x0A, 0x68, 0x42, 0xF0, 0x10, 0x02, 0x0A, 0x60, 
	0x0A, 0x68, 0x22, 0xF0, 0x03, 0x02, 0x0A, 0x60, 0x0A, 0x68, 0x42, 0xF0, 0x02, 0x02, 0x0A, 0x60, 
	0x41, 0x68, 0x41, 0x60, 0x41, 0x68, 0x41, 0x60, 0x41, 0x68, 0x41, 0xF4, 0x80, 0x61, 0x41, 0x60, 
	0x41, 0x68, 0x21, 0xF4, 0x7C, 0x11, 0x41, 0x60, 0x41, 0x68, 0x41, 0xF4, 0xE8, 0x11, 0x41, 0x60, 
	0x01, 0x68, 0x41, 0xF0, 0x80, 0x71, 0x01, 0x60, 0x01, 0x68, 0x89, 0x01, 0xFC, 0xD5, 0x41, 0x68, 
	0x21, 0xF0, 0x03, 0x01, 0x41, 0x60, 0x41, 0x68, 0x41, 0xF0, 0x02, 0x01, 0x41, 0x60, 0x41, 0x68, 
	0xC1, 0xF3, 0x81, 0x01, 0x02, 0x29, 0xFA, 0xD1, 0x0C, 0xBD, 0xAB, 0xE7, 0x10, 0xB5, 0x2A, 0x48, 
	0x01, 0x68, 0x41, 0xF0, 0x01, 0x01, 0x01, 0x60, 0x41, 0x68, 0x29, 0x4A, 0x11, 0x40, 0x41, 0x60, 
	0x01, 0x68, 0x28, 0x4A, 0x11, 0x40, 0x01, 0x60, 0x01, 0x68, 0x21, 0xF4, 0x80, 0x21, 0x01, 0x60, 
	0x41, 0x68, 0x21, 0xF4, 0xFE, 0x01, 0x41, 0x60, 0x4F, 0xF4, 0x1F, 0x01, 0x81, 0x60, 0xFF, 0xF7, 
	0xE4, 0xFF, 0x21, 0x49, 0x4F, 0xF0, 0x00, 0x60, 0x08, 0x60, 0x10, 0xBD, 0x10, 0xB5, 0x1A, 0x4A, 
	0x50, 0x68, 0x00, 0xF0, 0x0C, 0x01, 0x1D, 0x4B, 0x1D, 0x48, 0x00, 0x29, 0x0E, 0xD0, 0x04, 0x29, 
	0x0E, 0xD0, 0x08, 0x29, 0x0E, 0xD0, 0x03, 0x60, 0x51, 0x68, 0x19, 0x4A, 0xC1, 0xF3, 0x03, 0x11, 
	0x12, 0x1D, 0x51, 0x5C, 0x02, 0x68, 0xCA, 0x40, 0x02, 0x60, 0x10, 0xBD, 0x03, 0x60, 0xF3, 0xE7, 
	0x03, 0x60, 0xF1, 0xE7, 0x51, 0x68, 0x01, 0xF4, 0x70, 0x11, 0x53, 0x68, 0x03, 0xF4, 0x80, 0x33, 
	0x02, 0x24, 0x04, 0xEB, 0x91, 0x41, 0x33, 0xB1, 0x53, 0x68, 0x9B, 0x03, 0x07, 0xD5, 0x0D, 0x4B, 
	0x59, 0x43, 0x01, 0x60, 0xE0, 0xE7, 0x0B, 0x4B, 0x59, 0x43, 0x01, 0x60, 0xDC, 0xE7, 0x07, 0x4B, 
	0x59, 0x43, 0x01, 0x60, 0xD8, 0xE7, 0x00, 0x00, 0x00, 0x10, 0x02, 0x40, 0x00, 0x20, 0x02, 0x40, 
	0x00, 0x00, 0xFF, 0xF8, 0xFF, 0xFF, 0xF6, 0xFE, 0x08, 0xED, 0x00, 0xE0, 0x00, 0x12, 0x7A, 0x00, 
	0x00, 0x00, 0x00, 0x20, 0x00, 0x09, 0x3D, 0x00, 0x06, 0x48, 0x80, 0x47, 0x06, 0x48, 0x00, 0x47, 
	0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 0xFE, 0xE7, 
	0xFE, 0xE7, 0xFE, 0xE7, 0x2D, 0x03, 0x00, 0x08, 0x31, 0x01, 0x00, 0x08, 0x10, 0xB5, 0x9C, 0x49, 
	0x88, 0x42, 0x09, 0xD1, 0x01, 0x21, 0x04, 0x20, 0x00, 0xF0, 0x7D, 0xFA, 0x00, 0x21, 0xBD, 0xE8, 
	0x10, 0x40, 0x04, 0x20, 0x00, 0xF0, 0x77, 0xBA, 0x96, 0x49, 0x88, 0x42, 0x09, 0xD1, 0x01, 0x21, 
	0x08, 0x20, 0x00, 0xF0, 0x70, 0xFA, 0x00, 0x21, 0xBD, 0xE8, 0x10, 0x40, 0x08, 0x20, 0x00, 0xF0, 
	0x6A, 0xBA, 0x91, 0x49, 0x88, 0x42, 0x09, 0xD1, 0x01, 0x21, 0x10, 0x20, 0x00, 0xF0, 0x63, 0xFA, 
	0x00, 0x21, 0xBD, 0xE8, 0x10, 0x40, 0x10, 0x20, 0x00, 0xF0, 0x5D, 0xBA, 0x8B, 0x49, 0x88, 0x42, 
	0x09, 0xD1, 0x01, 0x21, 0x20, 0x20, 0x00, 0xF0, 0x56, 0xFA, 0x00, 0x21, 0xBD, 0xE8, 0x10, 0x40, 
	0x20, 0x20, 0x00, 0xF0, 0x50, 0xBA, 0x86, 0x49, 0x88, 0x42, 0x09, 0xD1, 0x01, 0x21, 0x40, 0x20, 
	0x00, 0xF0, 0x49, 0xFA, 0x00, 0x21, 0xBD, 0xE8, 0x10, 0x40, 0x40, 0x20, 0x00, 0xF0, 0x43, 0xBA, 
	0x80, 0x49, 0x88, 0x42, 0x09, 0xD1, 0x01, 0x21, 0x80, 0x20, 0x00, 0xF0, 0x3C, 0xFA, 0x00, 0x21, 
	0xBD, 0xE8, 0x10, 0x40, 0x80, 0x20, 0x00, 0xF0, 0x36, 0xBA, 0x7B, 0x49, 0x88, 0x42, 0x0A, 0xD1, 
	0x84, 0x15, 0x01, 0x21, 0x20, 0x46, 0x00, 0xF0, 0x2E, 0xFA, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 
	0x00, 0x21, 0x00, 0xF0, 0x28, 0xBA, 0x10, 0xBD, 0x10, 0xB5, 0x01, 0x21, 0x08, 0x46, 0x00, 0xF0, 
	0x22, 0xFA, 0x00, 0x21, 0xBD, 0xE8, 0x10, 0x40, 0x01, 0x20, 0x00, 0xF0, 0x1C, 0xBA, 0x2D, 0xE9, 
	0xF0, 0x41, 0x00, 0x22, 0xCC, 0x78, 0x04, 0xF0, 0x0F, 0x03, 0xE4, 0x06, 0x01, 0xD5, 0x8C, 0x78, 
	0x23, 0x43, 0x0C, 0x78, 0x4F, 0xF0, 0x0F, 0x07, 0x14, 0xF0, 0xFF, 0x0F, 0x4F, 0xF0, 0x01, 0x0C, 
	0x1C, 0xD0, 0x05, 0x68, 0x0C, 0xFA, 0x02, 0xF4, 0x0E, 0x88, 0x26, 0x40, 0xA6, 0x42, 0x11, 0xD1, 
	0x96, 0x00, 0x07, 0xFA, 0x06, 0xF8, 0x25, 0xEA, 0x08, 0x05, 0x03, 0xFA, 0x06, 0xF8, 0x48, 0xEA, 
	0x05, 0x05, 0xCE, 0x78, 0x28, 0x2E, 0x02, 0xD0, 0x48, 0x2E, 0x02, 0xD0, 0x02, 0xE0, 0x44, 0x61, 
	0x00, 0xE0, 0x04, 0x61, 0x52, 0x1C, 0x08, 0x2A, 0xE4, 0xD3, 0x05, 0x60, 0x0A, 0x88, 0xFF, 0x2A, 
	0x1E, 0xD9, 0x45, 0x68, 0x00, 0x22, 0x02, 0xF1, 0x08, 0x06, 0x0C, 0xFA, 0x06, 0xF4, 0x0E, 0x88, 
	0x26, 0x40, 0xA6, 0x42, 0x10, 0xD1, 0x96, 0x00, 0x07, 0xFA, 0x06, 0xF8, 0x25, 0xEA, 0x08, 0x05, 
	0x03, 0xFA, 0x06, 0xF8, 0x48, 0xEA, 0x05, 0x05, 0xCE, 0x78, 0x28, 0x2E, 0x00, 0xD1, 0x44, 0x61, 
	0xCE, 0x78, 0x48, 0x2E, 0x00, 0xD1, 0x04, 0x61, 0x52, 0x1C, 0x08, 0x2A, 0xE3, 0xD3, 0x45, 0x60, 
	0xBD, 0xE8, 0xF0, 0x81, 0x4F, 0xF6, 0xFF, 0x71, 0x01, 0x80, 0x02, 0x21, 0x81, 0x70, 0x04, 0x21, 
	0xC1, 0x70, 0x70, 0x47, 0x02, 0x46, 0x00, 0x20, 0x92, 0x68, 0x0A, 0x42, 0x00, 0xD0, 0x01, 0x20, 
	0x70, 0x47, 0x80, 0x68, 0x80, 0xB2, 0x70, 0x47, 0x02, 0x46, 0x00, 0x20, 0xD2, 0x68, 0x0A, 0x42, 
	0x00, 0xD0, 0x01, 0x20, 0x70, 0x47, 0xC0, 0x68, 0x80, 0xB2, 0x70, 0x47, 0x01, 0x61, 0x70, 0x47, 
	0x41, 0x61, 0x70, 0x47, 0x00, 0x2A, 0x01, 0xD0, 0x01, 0x61, 0x70, 0x47, 0x41, 0x61, 0x70, 0x47, 
	0xC1, 0x60, 0x70, 0x47, 0x41, 0xF4, 0x80, 0x32, 0x82, 0x61, 0x81, 0x61, 0x82, 0x61, 0x81, 0x69, 
	0x80, 0x69, 0x70, 0x47, 0x10, 0xB5, 0x2D, 0x4B, 0x1A, 0x68, 0x4F, 0xF6, 0x80, 0x74, 0x22, 0x40, 
	0x42, 0xEA, 0x00, 0x10, 0x08, 0x43, 0x18, 0x60, 0x10, 0xBD, 0x29, 0x49, 0xC8, 0x61, 0x70, 0x47, 
	0xF0, 0xB5, 0x26, 0x4C, 0x00, 0x28, 0x01, 0xDA, 0xE3, 0x69, 0x00, 0xE0, 0x63, 0x68, 0xC0, 0xF3, 
	0x03, 0x46, 0x42, 0x0D, 0x12, 0x01, 0x85, 0xB2, 0xC0, 0xF3, 0x01, 0x57, 0x95, 0x40, 0x03, 0x2F, 
	0x07, 0xD0, 0xC2, 0x02, 0x0C, 0xD5, 0x03, 0x22, 0xB2, 0x40, 0x93, 0x43, 0x43, 0xF0, 0x70, 0x62, 
	0x09, 0xE0, 0x23, 0xF0, 0x70, 0x62, 0x63, 0x68, 0x23, 0xF0, 0x70, 0x63, 0x63, 0x60, 0x02, 0xE0, 
	0xAB, 0x43, 0x43, 0xF0, 0x70, 0x62, 0x01, 0xB1, 0x2A, 0x43, 0x00, 0x28, 0x01, 0xDA, 0xE2, 0x61, 
	0xF0, 0xBD, 0x62, 0x60, 0xF0, 0xBD, 0x10, 0xB5, 0x8A, 0x07, 0x12, 0x0F, 0x0F, 0x23, 0x93, 0x40, 
	0x21, 0xF0, 0x03, 0x04, 0x0D, 0x49, 0x21, 0x44, 0x8C, 0x68, 0x9C, 0x43, 0x8C, 0x60, 0x8B, 0x68, 
	0x90, 0x40, 0x03, 0x43, 0x8B, 0x60, 0x10, 0xBD, 0x09, 0x49, 0xDC, 0x31, 0x08, 0x60, 0x70, 0x47, 
	0x00, 0x08, 0x01, 0x40, 0x00, 0x0C, 0x01, 0x40, 0x00, 0x10, 0x01, 0x40, 0x00, 0x14, 0x01, 0x40, 
	0x00, 0x18, 0x01, 0x40, 0x00, 0x1C, 0x01, 0x40, 0x00, 0x20, 0x01, 0x40, 0x00, 0x00, 0x01, 0x40, 
	0x00, 0x00, 0x20, 0x42, 0xB4, 0x48, 0x01, 0x68, 0x41, 0xF0, 0x01, 0x01, 0x01, 0x60, 0x41, 0x68, 
	0xB2, 0x4A, 0x11, 0x40, 0x41, 0x60, 0x01, 0x68, 0xB1, 0x4A, 0x11, 0x40, 0x01, 0x60, 0x01, 0x68, 
	0x21, 0xF4, 0x80, 0x21, 0x01, 0x60, 0x41, 0x68, 0x21, 0xF4, 0xFE, 0x01, 0x41, 0x60, 0x4F, 0xF4, 
	0x1F, 0x01, 0x81, 0x60, 0x70, 0x47, 0xA8, 0x49, 0x0A, 0x68, 0x22, 0xF4, 0x80, 0x32, 0x0A, 0x60, 
	0x0A, 0x68, 0x22, 0xF4, 0x80, 0x22, 0x0A, 0x60, 0xB0, 0xF5, 0x80, 0x3F, 0x07, 0xD0, 0xB0, 0xF5, 
	0x80, 0x2F, 0x03, 0xD1, 0x08, 0x68, 0x40, 0xF4, 0xA0, 0x20, 0x08, 0x60, 0x70, 0x47, 0x08, 0x68, 
	0x40, 0xF4, 0x80, 0x30, 0x08, 0x60, 0x70, 0x47, 0x03, 0x46, 0x00, 0x20, 0x59, 0x09, 0x9A, 0x4A, 
	0x01, 0x29, 0x0A, 0xD0, 0x02, 0x29, 0x0A, 0xD0, 0x51, 0x6A, 0x03, 0xF0, 0x1F, 0x02, 0x01, 0x23, 
	0x93, 0x40, 0x0B, 0x42, 0x00, 0xD0, 0x01, 0x20, 0x70, 0x47, 0x11, 0x68, 0xF5, 0xE7, 0x11, 0x6A, 
	0xF3, 0xE7, 0x18, 0xB5, 0x00, 0x20, 0x00, 0x90, 0x4F, 0xF4, 0xA0, 0x64, 0x31, 0x20, 0xFF, 0xF7, 
	0xE3, 0xFF, 0x00, 0x99, 0x49, 0x1C, 0x00, 0x91, 0x00, 0x99, 0xA1, 0x42, 0x01, 0xD0, 0x00, 0x28, 
	0xF4, 0xD0, 0x31, 0x20, 0xFF, 0xF7, 0xD8, 0xFF, 0x08, 0xB1, 0x01, 0x20, 0x18, 0xBD, 0x00, 0x20, 
	0x18, 0xBD, 0x85, 0x4A, 0x11, 0x68, 0x21, 0xF0, 0xF8, 0x01, 0x41, 0xEA, 0xC0, 0x00, 0x10, 0x60, 
	0x70, 0x47, 0x84, 0x49, 0x08, 0x60, 0x70, 0x47, 0x7F, 0x4B, 0x5A, 0x68, 0x22, 0xF4, 0x7C, 0x12, 
	0x08, 0x43, 0x10, 0x43, 0x58, 0x60, 0x70, 0x47, 0x7E, 0x49, 0x08, 0x66, 0x70, 0x47, 0x7A, 0x4A, 
	0x51, 0x68, 0x21, 0xF0, 0x03, 0x01, 0x01, 0x43, 0x51, 0x60, 0x70, 0x47, 0x76, 0x48, 0x40, 0x68, 
	0x00, 0xF0, 0x0C, 0x00, 0x70, 0x47, 0x74, 0x4A, 0x51, 0x68, 0x21, 0xF0, 0xF0, 0x01, 0x01, 0x43, 
	0x51, 0x60, 0x70, 0x47, 0x70, 0x4A, 0x51, 0x68, 0x21, 0xF4, 0xE0, 0x61, 0x01, 0x43, 0x51, 0x60, 
	0x70, 0x47, 0x6D, 0x4A, 0x51, 0x68, 0x21, 0xF4, 0x60, 0x51, 0x41, 0xEA, 0xC0, 0x00, 0x50, 0x60, 
	0x70, 0x47, 0x69, 0x4A, 0x00, 0x29, 0x03, 0xD0, 0x51, 0x7A, 0x01, 0x43, 0x51, 0x72, 0x70, 0x47, 
	0x51, 0x7A, 0x81, 0x43, 0x51, 0x72, 0x70, 0x47, 0x66, 0x49, 0xD8, 0x31, 0x08, 0x60, 0x70, 0x47, 
	0x61, 0x4A, 0x51, 0x68, 0x21, 0xF4, 0x40, 0x41, 0x01, 0x43, 0x51, 0x60, 0x70, 0x47, 0x5E, 0x49, 
	0x00, 0x22, 0x20, 0x31, 0x0A, 0x70, 0x01, 0xF8, 0x20, 0x29, 0x01, 0x28, 0x05, 0xD0, 0x04, 0x28, 
	0x02, 0xD1, 0x05, 0x20, 0x81, 0xF8, 0x20, 0x00, 0x70, 0x47, 0x01, 0x20, 0x81, 0xF8, 0x20, 0x00, 
	0x70, 0x47, 0x59, 0x49, 0x08, 0x60, 0x70, 0x47, 0x53, 0x49, 0x0A, 0x6A, 0x02, 0x43, 0x0A, 0x62, 
	0x70, 0x47, 0x55, 0x49, 0x44, 0x39, 0x08, 0x60, 0x70, 0x47, 0x10, 0xB5, 0x4E, 0x4A, 0x51, 0x68, 
	0x01, 0xF0, 0x0C, 0x01, 0x51, 0x4B, 0x00, 0x29, 0x27, 0xD0, 0x04, 0x29, 0x27, 0xD0, 0x08, 0x29, 
	0x27, 0xD0, 0x03, 0x60, 0x51, 0x68, 0x01, 0xF0, 0xF0, 0x01, 0x09, 0x09, 0x4C, 0x4B, 0x5C, 0x5C, 
	0x01, 0x68, 0xE1, 0x40, 0x41, 0x60, 0x54, 0x68, 0x04, 0xF4, 0xE0, 0x64, 0x24, 0x0A, 0x1C, 0x5D, 
	0x21, 0xFA, 0x04, 0xF4, 0x84, 0x60, 0x54, 0x68, 0x04, 0xF4, 0x60, 0x54, 0xE4, 0x0A, 0x1B, 0x5D, 
	0xD9, 0x40, 0xC1, 0x60, 0x52, 0x68, 0x02, 0xF4, 0x40, 0x42, 0x92, 0x0B, 0x40, 0x4B, 0x1B, 0x1F, 
	0x9A, 0x5C, 0xB1, 0xFB, 0xF2, 0xF1, 0x01, 0x61, 0x10, 0xBD, 0x03, 0x60, 0xDA, 0xE7, 0x03, 0x60, 
	0xD8, 0xE7, 0x51, 0x68, 0x01, 0xF4, 0x70, 0x11, 0x53, 0x68, 0x03, 0xF4, 0x80, 0x33, 0x02, 0x24, 
	0x04, 0xEB, 0x91, 0x41, 0x33, 0xB1, 0x53, 0x68, 0x9B, 0x03, 0x07, 0xD5, 0x35, 0x4B, 0x59, 0x43, 
	0x01, 0x60, 0xC7, 0xE7, 0x33, 0x4B, 0x59, 0x43, 0x01, 0x60, 0xC3, 0xE7, 0x2F, 0x4B, 0x59, 0x43, 
	0x01, 0x60, 0xBF, 0xE7, 0x28, 0x4A, 0x00, 0x29, 0x03, 0xD0, 0x51, 0x69, 0x01, 0x43, 0x51, 0x61, 
	0x70, 0x47, 0x51, 0x69, 0x81, 0x43, 0x51, 0x61, 0x70, 0x47, 0x23, 0x4A, 0x00, 0x29, 0x03, 0xD0, 
	0x91, 0x69, 0x01, 0x43, 0x91, 0x61, 0x70, 0x47, 0x91, 0x69, 0x81, 0x43, 0x91, 0x61, 0x70, 0x47, 
	0x1D, 0x4A, 0x00, 0x29, 0x03, 0xD0, 0xD1, 0x69, 0x01, 0x43, 0xD1, 0x61, 0x70, 0x47, 0xD1, 0x69, 
	0x81, 0x43, 0xD1, 0x61, 0x70, 0x47, 0x18, 0x4A, 0x00, 0x29, 0x03, 0xD0, 0xD1, 0x68, 0x01, 0x43, 
	0xD1, 0x60, 0x70, 0x47, 0xD1, 0x68, 0x81, 0x43, 0xD1, 0x60, 0x70, 0x47, 0x12, 0x4A, 0x00, 0x29, 
	0x03, 0xD0, 0x11, 0x69, 0x01, 0x43, 0x11, 0x61, 0x70, 0x47, 0x11, 0x69, 0x81, 0x43, 0x11, 0x61, 
	0x70, 0x47, 0x11, 0x49, 0x40, 0x39, 0x08, 0x60, 0x70, 0x47, 0x0E, 0x49, 0xC8, 0x64, 0x70, 0x47, 
	0x09, 0x49, 0xC8, 0x71, 0x70, 0x47, 0x08, 0x48, 0x41, 0x6A, 0x41, 0xF0, 0x80, 0x71, 0x41, 0x62, 
	0x70, 0x47, 0x01, 0x46, 0x00, 0x20, 0x04, 0x4A, 0x92, 0x68, 0x0A, 0x42, 0x00, 0xD0, 0x01, 0x20, 
	0x70, 0x47, 0x01, 0x49, 0x88, 0x72, 0x70, 0x47, 0x00, 0x10, 0x02, 0x40, 0x00, 0x00, 0xFF, 0xF8, 
	0xFF, 0xFF, 0xF6, 0xFE, 0x00, 0x00, 0x42, 0x42, 0x80, 0x04, 0x42, 0x42, 0x00, 0x12, 0x7A, 0x00, 
	0x18, 0x00, 0x00, 0x20, 0x00, 0x09, 0x3D, 0x00, 0x10, 0xB5, 0xE1, 0x49, 0x88, 0x42, 0x0A, 0xD1, 
	0x01, 0x21, 0x8C, 0x03, 0x20, 0x46, 0xFF, 0xF7, 0xB6, 0xFF, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 
	0x00, 0x21, 0xFF, 0xF7, 0xB0, 0xBF, 0xDB, 0x49, 0x88, 0x42, 0x0A, 0xD1, 0x01, 0x21, 0x4C, 0x04, 
	0x20, 0x46, 0xFF, 0xF7, 0xB3, 0xFF, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 0x00, 0x21, 0xFF, 0xF7, 
	0xAD, 0xBF, 0xD5, 0x49, 0x88, 0x42, 0x0A, 0xD1, 0x01, 0x21, 0x8C, 0x04, 0x20, 0x46, 0xFF, 0xF7, 
	0xA5, 0xFF, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 0x00, 0x21, 0xFF, 0xF7, 0x9F, 0xBF, 0xCF, 0x49, 
	0x88, 0x42, 0x0A, 0xD1, 0x01, 0x21, 0xCC, 0x04, 0x20, 0x46, 0xFF, 0xF7, 0x97, 0xFF, 0x20, 0x46, 
	0xBD, 0xE8, 0x10, 0x40, 0x00, 0x21, 0xFF, 0xF7, 0x91, 0xBF, 0xC9, 0x49, 0x88, 0x42, 0x0A, 0xD1, 
	0x01, 0x21, 0x0C, 0x05, 0x20, 0x46, 0xFF, 0xF7, 0x89, 0xFF, 0x20, 0x46, 0xBD, 0xE8, 0x10, 0x40, 
	0x00, 0x21, 0xFF, 0xF7, 0x83, 0xBF, 0x10, 0xBD, 0x30, 0xB5, 0x85, 0xB0, 0x04, 0x46, 0x0D, 0x46, 
	0x20, 0x8A, 0x4C, 0xF6, 0xFF, 0x71, 0x08, 0x40, 0xE9, 0x88, 0x01, 0x43, 0x21, 0x82, 0xA0, 0x89, 
	0x4E, 0xF6, 0xF3, 0x11, 0x08, 0x40, 0xA9, 0x88, 0x2A, 0x89, 0x11, 0x43, 0x6A, 0x89, 0x02, 0x43, 
	0x11, 0x43, 0xA1, 0x81, 0xA0, 0x8A, 0x4F, 0xF6, 0xFF, 0x41, 0x08, 0x40, 0xA9, 0x89, 0x01, 0x43, 
	0xA1, 0x82, 0x68, 0x46, 0xFF, 0xF7, 0xE9, 0xFE, 0xAD, 0x48, 0x84, 0x42, 0x01, 0xD1, 0x03, 0x98, 
	0x00, 0xE0, 0x02, 0x98, 0xA1, 0x89, 0x09, 0x04, 0x08, 0xD5, 0x00, 0xEB, 0xC0, 0x01, 0x01, 0xEB, 
	0x00, 0x10, 0x29, 0x68, 0x49, 0x00, 0xB0, 0xFB, 0xF1, 0xF0, 0x07, 0xE0, 0x00, 0xEB, 0xC0, 0x01, 
	0x01, 0xEB, 0x00, 0x10, 0x29, 0x68, 0x89, 0x00, 0xB0, 0xFB, 0xF1, 0xF0, 0x64, 0x22, 0xB0, 0xFB, 
	0xF2, 0xF1, 0x09, 0x01, 0x0B, 0x09, 0x6F, 0xF0, 0x18, 0x05, 0x6B, 0x43, 0x00, 0xEB, 0x83, 0x00, 
	0xA3, 0x89, 0x1D, 0x04, 0x4F, 0xF0, 0x32, 0x03, 0x07, 0xD5, 0x03, 0xEB, 0xC0, 0x00, 0xB0, 0xFB, 
	0xF2, 0xF0, 0x00, 0xF0, 0x07, 0x00, 0x08, 0x43, 0x06, 0xE0, 0x03, 0xEB, 0x00, 0x10, 0xB0, 0xFB, 
	0xF2, 0xF0, 0x00, 0xF0, 0x0F, 0x00, 0x08, 0x43, 0x20, 0x81, 0x05, 0xB0, 0x30, 0xBD, 0x4F, 0xF4, 
	0x16, 0x51, 0x01, 0x60, 0x00, 0x21, 0x81, 0x80, 0xC1, 0x80, 0x01, 0x81, 0x0C, 0x22, 0x42, 0x81, 
	0x81, 0x81, 0x70, 0x47, 0x10, 0xB5, 0x03, 0x8A, 0x4F, 0xF2, 0xFF, 0x02, 0x13, 0x40, 0x0A, 0x88, 
	0x4C, 0x88, 0x22, 0x43, 0x8C, 0x88, 0xC9, 0x88, 0x0C, 0x43, 0x22, 0x43, 0x1A, 0x43, 0x02, 0x82, 
	0x10, 0xBD, 0x00, 0x21, 0x01, 0x80, 0x41, 0x80, 0x81, 0x80, 0xC1, 0x80, 0x70, 0x47, 0x00, 0x29, 
	0x04, 0xD0, 0x81, 0x89, 0x41, 0xF4, 0x00, 0x51, 0x81, 0x81, 0x70, 0x47, 0x81, 0x89, 0x21, 0xF4, 
	0x00, 0x51, 0x81, 0x81, 0x70, 0x47, 0x10, 0xB5, 0x40, 0xF6, 0x6A, 0x13, 0xC1, 0xF3, 0x42, 0x13, 
	0x01, 0xF0, 0x1F, 0x04, 0x01, 0x21, 0xA1, 0x40, 0x01, 0x2B, 0x07, 0xD0, 0x02, 0x2B, 0x07, 0xD0, 
	0x14, 0x30, 0x3A, 0xB1, 0x02, 0x68, 0x0A, 0x43, 0x02, 0x60, 0x10, 0xBD, 0x0C, 0x30, 0xF8, 0xE7, 
	0x10, 0x30, 0xF6, 0xE7, 0x02, 0x68, 0x8A, 0x43, 0x02, 0x60, 0x10, 0xBD, 0x00, 0x2A, 0x03, 0xD0, 
	0x82, 0x8A, 0x0A, 0x43, 0x82, 0x82, 0x70, 0x47, 0x82, 0x8A, 0x8A, 0x43, 0x82, 0x82, 0x70, 0x47, 
	0x02, 0x8A, 0x22, 0xF0, 0x0F, 0x02, 0x02, 0x82, 0x02, 0x8A, 0x0A, 0x43, 0x02, 0x82, 0x70, 0x47, 
	0x82, 0x89, 0x22, 0xF4, 0x00, 0x62, 0x82, 0x81, 0x82, 0x89, 0x0A, 0x43, 0x82, 0x81, 0x70, 0x47, 
	0x00, 0x29, 0x04, 0xD0, 0x81, 0x89, 0x41, 0xF0, 0x02, 0x01, 0x81, 0x81, 0x70, 0x47, 0x81, 0x89, 
	0x21, 0xF0, 0x02, 0x01, 0x81, 0x81, 0x70, 0x47, 0x02, 0x8A, 0x22, 0xF0, 0x20, 0x02, 0x02, 0x82, 
	0x02, 0x8A, 0x0A, 0x43, 0x02, 0x82, 0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x01, 0x8A, 0x41, 0xF4, 
	0x80, 0x41, 0x01, 0x82, 0x70, 0x47, 0x01, 0x8A, 0x21, 0xF4, 0x80, 0x41, 0x01, 0x82, 0x70, 0x47, 
	0xC1, 0xF3, 0x08, 0x01, 0x81, 0x80, 0x70, 0x47, 0x80, 0x88, 0xC0, 0xF3, 0x08, 0x00, 0x70, 0x47, 
	0x81, 0x89, 0x41, 0xF0, 0x01, 0x01, 0x81, 0x81, 0x70, 0x47, 0x02, 0x8B, 0xD2, 0xB2, 0x02, 0x83, 
	0x02, 0x8B, 0x42, 0xEA, 0x01, 0x21, 0x01, 0x83, 0x70, 0x47, 0x02, 0x8B, 0x02, 0xF4, 0x7F, 0x42, 
	0x02, 0x83, 0x02, 0x8B, 0x0A, 0x43, 0x02, 0x83, 0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x81, 0x8A, 
	0x41, 0xF0, 0x20, 0x01, 0x81, 0x82, 0x70, 0x47, 0x81, 0x8A, 0x21, 0xF0, 0x20, 0x01, 0x81, 0x82, 
	0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x81, 0x8A, 0x41, 0xF0, 0x10, 0x01, 0x81, 0x82, 0x70, 0x47, 
	0x81, 0x8A, 0x21, 0xF0, 0x10, 0x01, 0x81, 0x82, 0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x81, 0x8A, 
	0x41, 0xF0, 0x08, 0x01, 0x81, 0x82, 0x70, 0x47, 0x81, 0x8A, 0x21, 0xF0, 0x08, 0x01, 0x81, 0x82, 
	0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x81, 0x89, 0x41, 0xF4, 0x00, 0x41, 0x81, 0x81, 0x70, 0x47, 
	0x81, 0x89, 0xC1, 0xF3, 0x0E, 0x01, 0x81, 0x81, 0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x81, 0x8A, 
	0x41, 0xF4, 0x00, 0x61, 0x81, 0x82, 0x70, 0x47, 0x81, 0x8A, 0x21, 0xF4, 0x00, 0x61, 0x81, 0x82, 
	0x70, 0x47, 0x82, 0x8A, 0x22, 0xF0, 0x04, 0x02, 0x82, 0x82, 0x82, 0x8A, 0x0A, 0x43, 0x82, 0x82, 
	0x70, 0x47, 0x00, 0x29, 0x04, 0xD0, 0x81, 0x8A, 0x41, 0xF0, 0x02, 0x01, 0x81, 0x82, 0x70, 0x47, 
	0x81, 0x8A, 0x21, 0xF0, 0x02, 0x01, 0x81, 0x82, 0x70, 0x47, 0x02, 0x46, 0x00, 0x20, 0x12, 0x88, 
	0x0A, 0x42, 0x00, 0xD0, 0x01, 0x20, 0x70, 0x47, 0x8A, 0x05, 0xC9, 0x43, 0x01, 0x80, 0x70, 0x47, 
	0x70, 0xB5, 0x00, 0x24, 0x40, 0xF6, 0x6A, 0x12, 0xC1, 0xF3, 0x42, 0x13, 0x01, 0xF0, 0x1F, 0x05, 
	0x01, 0x26, 0x06, 0xFA, 0x05, 0xF2, 0x01, 0x2B, 0x0C, 0xD0, 0x02, 0x2B, 0x0D, 0xD0, 0x83, 0x8A, 
	0x13, 0x40, 0x09, 0x0A, 0x8E, 0x40, 0x00, 0x88, 0x30, 0x40, 0x0B, 0xB1, 0x00, 0xB1, 0x01, 0x24, 
	0x20, 0x46, 0x70, 0xBD, 0x83, 0x89, 0x13, 0x40, 0xF3, 0xE7, 0x03, 0x8A, 0x13, 0x40, 0xF0, 0xE7, 
	0x40, 0xF6, 0x6A, 0x12, 0x0A, 0x0A, 0x01, 0x21, 0x91, 0x40, 0xC9, 0x43, 0x01, 0x80, 0x70, 0x47, 
	0x00, 0x38, 0x01, 0x40, 0x00, 0x44, 0x00, 0x40, 0x00, 0x48, 0x00, 0x40, 0x00, 0x4C, 0x00, 0x40, 
	0x00, 0x50, 0x00, 0x40, 0x06, 0x4C, 0x07, 0x4D, 0x06, 0xE0, 0xE0, 0x68, 0x40, 0xF0, 0x01, 0x03, 
	0x94, 0xE8, 0x07, 0x00, 0x98, 0x47, 0x10, 0x34, 0xAC, 0x42, 0xF6, 0xD3, 0xFF, 0xF7, 0xEC, 0xF9, 
	0xC8, 0x0D, 0x00, 0x08, 0xE8, 0x0D, 0x00, 0x08, 0x01, 0x4A, 0x02, 0x49, 0x00, 0xF0, 0x13, 0xB8, 
	0x29, 0x02, 0x00, 0x08, 0x28, 0x00, 0x00, 0x20, 0x02, 0xE0, 0x08, 0xC8, 0x12, 0x1F, 0x08, 0xC1, 
	0x00, 0x2A, 0xFA, 0xD1, 0x70, 0x47, 0x70, 0x47, 0x00, 0x20, 0x01, 0xE0, 0x01, 0xC1, 0x12, 0x1F, 
	0x00, 0x2A, 0xFB, 0xD1, 0x70, 0x47, 0x2D, 0xE9, 0xF0, 0x41, 0x16, 0x46, 0x0F, 0x46, 0x04, 0x46, 
	0x00, 0x25, 0x03, 0xE0, 0x39, 0x46, 0xB0, 0x47, 0x64, 0x1C, 0x6D, 0x1C, 0x20, 0x78, 0x00, 0x28, 
	0xF8, 0xD1, 0x28, 0x46, 0xBD, 0xE8, 0xF0, 0x81, 0x01, 0x00, 0x03, 0x10, 0x00, 0x80, 0x02, 0x48, 
	0x00, 0x02, 0x03, 0x18, 0x00, 0x04, 0x02, 0x04, 0xE8, 0x0D, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 
	0x2C, 0x00, 0x00, 0x00, 0x78, 0x0D, 0x00, 0x08, 0x14, 0x0E, 0x00, 0x08, 0x2C, 0x00, 0x00, 0x20, 
	0x04, 0x04, 0x00, 0x00, 0x88, 0x0D, 0x00, 0x08, 0x00, 0xA2, 0x4A, 0x04, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x02, 0x04, 0x06, 0x08, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 
	0x00, 0x00, 0x00, 0x00, 
};


void SerialInit(void)
{
	USART_InitTypeDef USART_InitStructure;
	
#ifdef __STM32F10x_CONF_H
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_Init(GPIOA, &(GPIO_InitTypeDef){GPIO_Pin_2, GPIO_Speed_10MHz, GPIO_Mode_AF_PP});			// UART2-TX
	GPIO_Init(GPIOA, &(GPIO_InitTypeDef){GPIO_Pin_3, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING});		// UART2-RX

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
#endif
#ifdef __STM32F4xx_CONF_H
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_Init(GPIOA, &(GPIO_InitTypeDef){GPIO_Pin_2, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL});
    GPIO_Init(GPIOA, &(GPIO_InitTypeDef){GPIO_Pin_3, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL});

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
#endif
	USART_InitStructure.USART_BaudRate = 57600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_Init(USART2, &USART_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
}

/****************************************************************************************************************************************** 
* 函数名称:	fputc()
* 功能说明: printf()底层输出函数
* 输    入: int ch	要输出的字符
*			FILE *f
* 输    出: 无
* 注意事项: 无
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
	USART_SendData(USART2, ch);
	
	return ch;
}
