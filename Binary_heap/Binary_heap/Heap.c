#include"Heap.h"
void Swap(HPDateType* p1, HPDateType* p2)
{
	assert(p1 && p2);
	int a = *p1;
	*p1 = *p2;
	*p2 = a;
}

void AdjustUp(HPDateType* a, int child)
{
	int parent = (child - 1) / 2;//这个写在外面为什么好
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
	
}
void AdjustDown(HPDateType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//这个顺序不能写反
		{
			child++;
		}
		//此时找到最大的孩子
		//并且保证了左右都不越界；
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPInit(HP* php)
{
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HPDestroy(HP* php)
{
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HPPush(HP* php, HPDateType x)
{
	//先判断满了没有
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : (php->capacity) * 2;
		HPDateType*  temp = (HPDateType*)realloc(php->a, sizeof(HPDateType) * newcapacity);
		if (temp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = temp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	//向上调整
	AdjustUp(php->a, php->size-1);
}
void HPPop(HP* php)
{
	assert(php);
	assert(php->size != 0);
	Swap(&(php->a[php->size - 1]), &php->a[0]);
	php->size--;
	AdjustDown(php->a, php->size, 0);

}
HPDateType HPTop(HP* php)
{
	assert(php);
	assert(php->size != 0);
	return php->a[0];
}
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


//void CreatHeap(int* a; int k)
//{
//	int i = 1;
//	for (i; i < k; i++)
//	{
//		AdjustUp(a, i);
//	}
//}
void CreatHeap(int* a, int n)
{
	// 1. 建堆
	int i = (n-2)/2;
	for (i; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
}

//堆排序
void HeapSort(int* a, int n)
{
	// 1. 建堆
	int i = (n - 2) / 2;
	for (i; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	// 2. 排序
	int end = n - 1;
	while (end)
	{
		//Swap(&a[0], &a[end]);
		int tmp = a[0];
		a[0] = a[end];
		a[end] = tmp;
		AdjustDown(a, end, 0);
		end--;
	}
	
}

