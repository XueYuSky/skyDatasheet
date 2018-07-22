//基本指令：
#define CLEAR_F    0x01           //将DDRAM填满“20H”，并且设定DDRAM的地址计数器(AC)到“00H”
#define ADDR_F     0x02         //设定DDRAM的地址计数到“00H”，并且将游标移到开头

//原点位置
#define OFF_DIS_F  0x08         //显示关
#define ON_DIS_F   0x0c         //开显示
#define YB_DIS_F   0x0e        //游标显示
#define YBFB_DIS_F 0x0f       //游标反白
#define YBLM_F     0x10         //游标左移
#define YBRM_F     0x14         //游标右移
#define ZHTLM_F    0x18          //整体左移
#define ZHTRM_F    0x1c           //整体右移
#define BASFUN_F   0x30          //使用基本功能
#define MORFUN_F   0x34             //使用扩展功能
#define ADD_CG     0x40          //设定CGRAM位置，ADD_CG|
#define ADD_DD     0x80           //设定DDRAM地址，ADD_DD|
//扩展功能
#define DM_S       0x01          //第二功能，待命模式
#define JDON_S     0x03           //允许卷动位置
#define IRON_S     0x02           //允许输入IRAM位址
#define FB01_S     0x04           //第一行反白
#define FB02_S     0x05           //第二行反白
#define FB03_S     0x05           //第三行反白
#define FB04_S     0x07           //第四行反白
#define SHMON_S    0x08           //进入睡眠
#define SHMOFF_S   0x0c           //退出睡眠
#define JDADD_S    0x40           //SR=1设定卷动位址,SR=0设定IRAM位址
#define NULL       0x00

#ifndef _12864_H
#define _12864_H
#ifdef _12864_C
void WriteInst(uchar,bit);			//写指令到指令暂存器（ＩＲ）函数  Rs=L;RW=L
void WriteData(char Data);		//写数据到数据暂存器　　　　　　      RS=H;RW=L　　　　
uchar ReadData(void);			//读出数据						      RS=H;RW=H
uchar ReadBusy(void);				//读忙　及地址记数器（ＡＣ）的状态    RS=L;RW=H
void TestBusy(void);
void Init12864(void);
void AutoDischar(char *p,uchar ,uchar); //显示字符程序，给字符首地址以及坐标点X：0~8,Y：1~4
void MakePic(char *p);
#else 
extern void WriteInst(uchar,bit);			//写指令到指令暂存器（ＩＲ）函数  Rs=L;RW=L
extern void WriteData(char Data);		//写数据到数据暂存器　　　　　　      RS=H;RW=L　　　　
extern uchar ReadData(void);			//读出数据						      RS=H;RW=H
extern uchar ReadBusy(void);				//读忙　及地址记数器（ＡＣ）的状态    RS=L;RW=H
extern void TestBusy(void);
extern void Init12864(void);
extern void AutoDischar(char *p,uchar x,uchar y); //显示字符程序，给字符首地址以及坐标点X：0~8,Y：1~4
extern void MakePic(char *p);
#endif
#endif 