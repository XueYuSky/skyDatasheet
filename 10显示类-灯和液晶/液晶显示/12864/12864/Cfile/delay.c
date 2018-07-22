#define _DELAY_C
#include "includes.h"
void Delay5ms(uchar times){
	uchar i,k;
	for(;times>0;times--)
		for(i=10;i>0;i--)
			for(k=250;k>0;k--);
}
//===========================================
void Delay7us(uchar times){
	for(;times;times--){
		_nop_();
	}
}