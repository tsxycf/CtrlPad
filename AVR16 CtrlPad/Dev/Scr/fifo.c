/*
  ******************************************************************************
  * @file    fifo.c
  * @author  chenfeifei  2018-4-23
  * @brief   用数组实现循环队列
  ******************************************************************************
*/


#include "stdint.h"
#include <fifo.h>


/********************************************************
 *初始化函数的实现
 ********************************************************/
void initQueue(QUEUE * pQueue, uint8_t *pBuffer)
{
	pQueue->pBase = pBuffer;      //分配内存
	pQueue->front = 0;            //初始化时，front（头）和rear（尾）值均为0
	pQueue->rear = 0;
	return;
}

/********************************************************
 *入队函数的实现
 *******************************************************/
bool enQueue(QUEUE * pQueue, uint8_t value)
{
	if(isFull(pQueue))
	{
		return FALSE;
	}
	else
	{
		//向队列中添加新元素
		pQueue->pBase[pQueue->rear] = value;
		//将rear赋予新的合适的值
		pQueue->rear = (pQueue->rear+1) % MAXSIZE;
		return TRUE;
	}
}
/*******************************************************
 *出队函数的实现
 ******************************************************/
bool outQueue(QUEUE * pQueue, uint8_t *pValue)
{
	//如果队列为空,则返回FALSE
	if(isEmpty(pQueue))
	{
		return FALSE;
	}
	else
	{
		*pValue = pQueue->pBase[pQueue->front];       //先进先出
		pQueue->front = (pQueue->front+1) % MAXSIZE;      //移到下一位置
		return TRUE;
	}
}
/*******************************************************
 *遍历队列的函数实现
 ******************************************************/
void traverseQueue(QUEUE * pQueue)
{
	int i = pQueue->front;           //从头开始遍历
	while(i != pQueue->rear)     //如果没有到达rear位置，就循环
	{
		i = (i+1) % MAXSIZE;              //移到下一位置
	}
	return;
}
/*******************************************************
 *判断队列是否满的函数的实现
 ******************************************************/
bool isFull(QUEUE * pQueue)
{
	if((pQueue->rear+1) % MAXSIZE == pQueue->front)     //队列满
		return TRUE;
	else
		return FALSE;
}
/*******************************************************
 *判断队列是否为空函数的实现
 ******************************************************/
bool isEmpty(QUEUE * pQueue)
{
	if(pQueue->front == pQueue->rear)
		return TRUE;
	else
		return FALSE;
}

