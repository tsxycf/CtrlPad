/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff 
 *Describe: 
 */
 
#ifndef __main_h
#define __main_h

typedef struct MotorClassDef
{
	uint8_t ID;		//电机标号
	uint16_t speed;	//电机速度
	uint8_t	direction;//电机运行方向
	uint8_t brake;	//电机抱闸
	
} MotorClass;		//描述电机行为

typedef struct StandardClassDef
{
	uint8_t ID;		//云台标号
	uint8_t up;		//上
	uint8_t down;	//下
	uint8_t left;	//左
	uint8_t right;	//右
	uint8_t light;	//灯
	uint8_t wiper;	//雨刷
	
} StandardClass;		//描述云台行为


typedef struct GeneralClassDef
{
	uint8_t ID;			//透传设备标号
	uint8_t data[8];	//透传8字节
	
} GeneralClass;			//描述透传行为


typedef struct CtrlPadDef
{
	uint8_t OptMod;				//操作模式
	MotorClass SuvSys_ARM1;		//大臂
	MotorClass SuvSys_ARM2;		//二臂
	MotorClass SuvSys_ARM3;		//三臂
	MotorClass SuvSys_ARM4;		//四臂
	MotorClass SuvSys_ARM5;		//
	StandardClass SuvSys_yuntai;//
	GeneralClass SuvSys_ transfer;//
}




#endif



