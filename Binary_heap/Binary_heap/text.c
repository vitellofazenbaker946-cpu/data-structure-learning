//#include"Heap.h"
//#include<time.h>
//
////创造随机数字 催在数组里
//void CreateNDate()
//{
//	int n = 1000;
//	srand(time(0));//bbbbbbbb
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	for (int i = 0; i < n; ++i)//bbbb
//	{
//		int x = (rand() + i) % 10000;//bbbbb
//		fprintf(fin, "%d\n", x);
//	}
//	fclose(fin);
//
//}
//void text3()
//{
//	CreateNDate();
//	int k = 10;
//	//建一个k哥的堆；
//	//再把读取文件前k个
//	int* kminheap = (int*)malloc(sizeof(int) * k);
//	const char* file = "data.txt";
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//
//	// 读取文件中前k个数
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fout, "%d", &kminheap[i]);
//	}
//	//向下建队
//	for (int i = (k - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(kminheap, k, i);
//	}
//	//开始读取剩下的n-k个数
//	int x = 0;
//	while (fscanf(fout, "%d", &x) == 1)
//	{
//		if (x > kminheap[0])
//		{
//			kminheap[0] = x;
//			AdjustDown(kminheap, k, 0);
//		}
//	}
//	fclose(fout);
//	printf("最大前%d个数：", k);
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", kminheap[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	text3();
//	return 0;
//}
#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 创建随机数据写入文件
void CreateNDate()
{
    int n = 1000;
    srand(time(0));

    FILE* fin = fopen("data.txt", "w");
    if (fin == NULL)
    {
        perror("fopen error");
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        int x = (rand() + i) % 10000;
        fprintf(fin, "%d\n", x);
    }

    fclose(fin);
}

void text3()
{
    CreateNDate();

    int k = 10;
    int* heap = (int*)malloc(sizeof(int) * k);
    if (heap == NULL)
    {
        perror("malloc error");
        return;
    }

    FILE* fout = fopen("data.txt", "r");
    if (fout == NULL)
    {
        perror("fopen error");
        return;
    }

    // 读前k个
    for (int i = 0; i < k; i++)
    {
        fscanf(fout, "%d", &heap[i]);
    }

    // 建小堆
    for (int i = (k - 2) / 2; i >= 0; --i)
    {
        AdjustDown(heap, k, i);
    }

    int x = 0;
    while (fscanf(fout, "%d", &x) == 1)
    {
        if (x > heap[0])
        {
            heap[0] = x;
            AdjustDown(heap, k, 0);
        }
    }

    printf("TopK: ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    fclose(fout);
    free(heap);
}

int main()
{
    text3();
    return 0;
}