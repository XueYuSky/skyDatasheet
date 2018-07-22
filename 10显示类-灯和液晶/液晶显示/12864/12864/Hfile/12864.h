//����ָ�
#define CLEAR_F    0x01           //��DDRAM������20H���������趨DDRAM�ĵ�ַ������(AC)����00H��
#define ADDR_F     0x02         //�趨DDRAM�ĵ�ַ��������00H�������ҽ��α��Ƶ���ͷ

//ԭ��λ��
#define OFF_DIS_F  0x08         //��ʾ��
#define ON_DIS_F   0x0c         //����ʾ
#define YB_DIS_F   0x0e        //�α���ʾ
#define YBFB_DIS_F 0x0f       //�α귴��
#define YBLM_F     0x10         //�α�����
#define YBRM_F     0x14         //�α�����
#define ZHTLM_F    0x18          //��������
#define ZHTRM_F    0x1c           //��������
#define BASFUN_F   0x30          //ʹ�û�������
#define MORFUN_F   0x34             //ʹ����չ����
#define ADD_CG     0x40          //�趨CGRAMλ�ã�ADD_CG|
#define ADD_DD     0x80           //�趨DDRAM��ַ��ADD_DD|
//��չ����
#define DM_S       0x01          //�ڶ����ܣ�����ģʽ
#define JDON_S     0x03           //�����λ��
#define IRON_S     0x02           //��������IRAMλַ
#define FB01_S     0x04           //��һ�з���
#define FB02_S     0x05           //�ڶ��з���
#define FB03_S     0x05           //�����з���
#define FB04_S     0x07           //�����з���
#define SHMON_S    0x08           //����˯��
#define SHMOFF_S   0x0c           //�˳�˯��
#define JDADD_S    0x40           //SR=1�趨��λַ,SR=0�趨IRAMλַ
#define NULL       0x00

#ifndef _12864_H
#define _12864_H
#ifdef _12864_C
void WriteInst(uchar,bit);			//дָ�ָ���ݴ������ɣң�����  Rs=L;RW=L
void WriteData(char Data);		//д���ݵ������ݴ���������������      RS=H;RW=L��������
uchar ReadData(void);			//��������						      RS=H;RW=H
uchar ReadBusy(void);				//��æ������ַ�����������ã���״̬    RS=L;RW=H
void TestBusy(void);
void Init12864(void);
void AutoDischar(char *p,uchar ,uchar); //��ʾ�ַ����򣬸��ַ��׵�ַ�Լ������X��0~8,Y��1~4
void MakePic(char *p);
#else 
extern void WriteInst(uchar,bit);			//дָ�ָ���ݴ������ɣң�����  Rs=L;RW=L
extern void WriteData(char Data);		//д���ݵ������ݴ���������������      RS=H;RW=L��������
extern uchar ReadData(void);			//��������						      RS=H;RW=H
extern uchar ReadBusy(void);				//��æ������ַ�����������ã���״̬    RS=L;RW=H
extern void TestBusy(void);
extern void Init12864(void);
extern void AutoDischar(char *p,uchar x,uchar y); //��ʾ�ַ����򣬸��ַ��׵�ַ�Լ������X��0~8,Y��1~4
extern void MakePic(char *p);
#endif
#endif 