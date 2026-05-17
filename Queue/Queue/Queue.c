#include"Queue.h"
//初始化销毁
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//注意 没写上
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 队列的尾插
void QueuePush(Queue* pq, QDateType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->ptail == NULL)//说明是空链表
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
//队列的头删
void QueuePop(Queue* pq)
{
	assert(pq);
	//assert(pq->phead);
	assert(pq->size != 0);
	if (pq->size == 1)
	{
		free(pq->phead);
		pq->ptail = pq->phead = NULL;
	}
	Queue* next = (pq->phead)->next;
	free(pq->phead);
	pq->phead = next;

	pq->size--;
}


// 队列取头 取尾
QDateType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDateType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	//assert(pq->size != 0);应该也行反正
	return pq->ptail->val;
}


//取值
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

//验空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}




