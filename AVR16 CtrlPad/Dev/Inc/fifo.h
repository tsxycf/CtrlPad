/*
  ******************************************************************************
  * @file    fifo.h
  * @author  chenfeifei  2018-4-23
  * @brief   Header file of fifo module.
  ******************************************************************************
*/


#ifndef _FIFO_H_
#define _FIFO_H_

#include"stdint.h"

#define MAXSIZE  16	//定义队列区大小

typedef enum {FALSE = 0,TRUE = 1} bool;

typedef struct Queue
{
		uint8_t *pBase;    //用于定义整个FIFO缓冲区首地址
		uint8_t front;      //指向头节点
		uint8_t rear;       //指向最后一个元素的下一个节点，空栈操作
} QUEUE;

extern void initQueue(QUEUE * pQueue, uint8_t *pBuffer);  //队列初始化函数
extern bool isEmpty(QUEUE * pQueue);   				//判断队列是否为空
extern bool isFull(QUEUE * pQueue);   				//判断队列是否为满
extern bool enQueue(QUEUE * pQueue, uint8_t value); 	//入队列操作
extern bool outQueue(QUEUE * pQueue, uint8_t * pValue); //出队列操作
extern void traverseQueue(QUEUE * pQueue);   		//编列队列操作


#endif


