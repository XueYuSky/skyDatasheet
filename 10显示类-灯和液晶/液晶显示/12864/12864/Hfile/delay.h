#ifndef _DELAY_H
#define _DELAY_H
#ifdef _DELAY_C
void Delay5ms(uchar);
void Delay7us(uchar);
#else 
extern void Delay5ms(uchar);
extern void Delay7us(uchar);
#endif
#endif