#include "includes.h"
#include "code.h"
//#define C_
/*++++++++++++++++++++++++++++++++++++++++++++++++*/
//#define 
/*++++++++++++++++++++++++++++++++++++++++++++++++*/
void main(void){
	char *p;
	Init12864();
	p=&code1;
	AutoDischar(p,0,1);
//	WriteInst(MORFUN_F,1);
//	WriteInst(FB04_S,1);  
	while(1);
}