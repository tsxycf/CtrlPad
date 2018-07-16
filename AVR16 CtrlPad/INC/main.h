/*
 * Revision: V1.0
 * Date: 2018-6-13
 * Author: cff 
 *Describe: 
 */
 
#ifndef __main_h
#define __main_h




typedef struct PanelClassDef
{

/* button 为二值状态变量 ON OFF  */
	uint8_t key1State;
	uint8_t key2State;
	uint8_t key3tate;
	uint8_t key4State;
	uint8_t key5State;
	uint8_t key6State;
	uint8_t key7State;
	uint8_t key8State;	

/* button 为三值状态变量 UP DOWN MIDDLE  */
	uint8_t button1State;
	uint8_t button2State;
	uint8_t button3State;
	uint8_t button4State;
	uint8_t button5State;
	uint8_t button6State;
	uint8_t button7State;
	uint8_t button8State;

/* joystick 为多值变量，一般为AD值 */
	uint16_t  joystick1;
	uint16_t  joystick2;
	uint16_t  joystick3;
	uint16_t  joystick4;
	uint16_t  joystick5;
	uint16_t  joystick6;
	uint16_t  joystick7;
	uint16_t  joystick8;

}PanelClass;




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


typedef struct CtrlPadClassDef
{
	uint8_t OptMod;				//操作模式
	MotorClass SubSys_ARM1;		//大臂
	MotorClass SubSys_ARM2;		//二臂
	MotorClass SubSys_ARM3;		//三臂
	MotorClass SubSys_ARM4;		//四臂
	MotorClass SubSys_ARM5;		//
	StandardClass SubSys_yuntai;//
	GeneralClass SubSys_transfer;//
}CtrlPadClass;




#endif



