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

#define MAXSIZE  16	//�����������С

typedef enum {FALSE = 0,TRUE = 1} bool;

typedef struct Queue
{
		uint8_t *pBase;    //���ڶ�������FIFO�������׵�ַ
		uint8_t front;      //ָ��ͷ�ڵ�
		uint8_t rear;       //ָ�����һ��Ԫ�ص���һ���ڵ㣬��ջ����
} QUEUE;

extern void initQueue(QUEUE * pQueue, uint8_t *pBuffer);  //���г�ʼ������
extern bool isEmpty(QUEUE * pQueue);   				//�ж϶����Ƿ�Ϊ��
extern bool isFull(QUEUE * pQueue);   				//�ж϶����Ƿ�Ϊ��
extern bool enQueue(QUEUE * pQueue, uint8_t value); 	//����в���
extern bool outQueue(QUEUE * pQueue, uint8_t * pValue); //�����в���
extern void traverseQueue(QUEUE * pQueue);   		//���ж��в���


#endif


