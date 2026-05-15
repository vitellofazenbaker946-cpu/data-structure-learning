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

void Swap(HPDateType* p1, HPDateType* p2);
void AdjustUp(HPDateType* a, int child);
void AdjustDown(HPDateType* a, int n, int parent);
void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php, HPDateType x);
void HPPop(HP* php);
HPDateType HPTop(HP* php);
bool HPEmpty(HP* php);

void CreatHeap(int* a, int n);
void HeapSort(int* a, int n);
