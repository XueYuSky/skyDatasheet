#define _12864_C
#include "includes.h"
sbit RS_12864   =P2^0;	   //RS
sbit RW_12864   =P2^1;   //RW
sbit E_12864    =P2^2;   //E
sbit PSB_12864  =P2^3;
sbit RESET_12864=P2^5;
void WriteInst(uchar Inst,bit b){
	if(b)TestBusy();
	RS_12864=L;
	RW_12864=L;
//	_nop_();
	E_12864 =H;
//	_nop_();
    D_12864 =Inst;
	E_12864 =L;
//	_nop_();
}
uchar ReadBusy(void){
	uchar Busy_8;
	D_12864=0xFF;
	RS_12864=L;
	RW_12864=H;
	_nop_();
	E_12864 =H;
	_nop_();
	Busy_8=D_12864; 
	E_12864 =L;
	_nop_();
	D_12864=0xFF;
	RS_12864=L;
	RW_12864=H;
	_nop_();
	E_12864 =H;
	_nop_();
	Busy_8=D_12864; 
	E_12864 =L;
	_nop_();
	return Busy_8;
}
void TestBusy(void){
	bit b=0;
	uchar busy;
	do{
	busy=ReadBusy();
	b=(bit)(busy&0x80);
	}while(b);
}
void WriteData(char Data){
	TestBusy();
	RS_12864=H;
	RW_12864=L;
//	_nop_();
	E_12864 =H;
//	_nop_();
	D_12864=Data;
	E_12864 =L;
//	_nop_();
}
uchar ReadData(void){
	uchar Data;
	RS_12864=H;
	RW_12864=H;
	_nop_();
	E_12864 =H;
	_nop_();
	Data=D_12864;
	E_12864 =L;
	_nop_();
	return Data;
}
//=======================================
void Init12864(void){
	Delay5ms(8);
	RESET_12864=L;
	Delay5ms(1);
	RESET_12864=H;
	Delay5ms(1);
	WriteInst(0X38,0);
	Delay5ms(1);
	WriteInst(0X38,0);
	Delay5ms(1);
	WriteInst(0X38,0);
	Delay5ms(1);
	WriteInst(0x38,1);
	WriteInst(0X08,1);
	WriteInst(0X01,1);
	WriteInst(0X06,1);
	WriteInst(0X0c,1);
}
//===========================================
void AutoDischar(char *p,uchar x,uchar y){
	uchar yy;
	WriteInst(0x38,1);
	if(y==1)yy=0;
	else if(y==2)yy=0x10;
	else if(y==3)yy=0x08;
	else yy=0x18;
	WriteInst(0x80|x|yy,1);
	while(*p!='\0'){
		WriteData(*p++);
	}
}
void MakePic(char *p){
	uchar i;
	uchar j;
	WriteInst(0x34,1);
	for(j=0;j<32;j++){
			WriteInst(0x80|j,1);
			WriteInst(0x80,1);
			for(i=0;i<16;i++)WriteData(*p++);
	}
	for(j=0;j<32;j++){
			WriteInst(0x80|j,1);
			WriteInst(0x88,1);
			for(i=0;i<16;i++)WriteData(*p++);
	}
	WriteInst(0x36,1);
}

/*
void DisALine(char *p,uchar x,uchar y){
	WriteInst(0x34,1);
} 
*/