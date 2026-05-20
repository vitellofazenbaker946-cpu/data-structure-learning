#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* a;
	int size;
	int capacity;
}HP;

void AdjustUp(HPDateType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}

	}

	void AdjustDown(HPDateType * a, int n, int parent)
	{
		int child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && a[child] < a[child + 1])
			{
				++child;
			}
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

