#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int QDateType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDateType val;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* phead;
	struct QueueNode* ptail;
	int size;
} Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

// 队列的尾插
void QueuePush(Queue* pq, QDateType x);
//队列的头删
void QueuePop(Queue* pq);

// 队列取头 取尾
QDateType QueueFront(Queue* pq);
QDateType QueueBack(Queue* pq);

//取值
int QueueSize(Queue* pq);

//验空
bool QueueEmpty(Queue* pq);