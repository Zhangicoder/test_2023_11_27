#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void getmoviedata(int*, int);//读入信息
void sort(int*, int);//排序
double average(int*, int);//平均数
int mode(int*, int);//众数
double median(int*, int);//中位数
int main()
{
	int num;
	int *moviedata;
	printf("请输入学生人数");
	scanf("%d", &num);
	moviedata = (int*)malloc(num * sizeof(int));
	getmoviedata(moviedata, num);
	sort(moviedata, num);
	for (int i = 0; i < num; i++)
		printf("%d ", *(moviedata + i));
	printf("\n");
	//打印平均值
	printf("平均值为>");
	printf("%lf\n", average(moviedata, num));
	//打印中位数
	printf("中位数为>");
	printf("%lf\n",median(moviedata,num));
	//打印众数
	if (mode(moviedata,num) == -1)
		printf("没有众数");
	else
		printf("众数为> %d\n", mode(moviedata,num));
	//回收内存
	free(moviedata);
	return 0;
}
void getmoviedata(int* arr, int num)
{
	printf("输入每一个学生看的电影数目\n");
	for (int i = 0; i < num; i++)
	{
		printf("学生1 %d>", i + 1);
		scanf("%d", arr + i);
	}
}
void sort(int* arr, int num)
{
	for (int k = 0; k < num - 1; k++)
	{
		int min = k;
		for (int pos = k+1; pos < num ; pos++)
		{
			if (*(arr + pos) < *(arr+min))
			{
				min = pos;
			}
		}
		int temp;
		temp = *(arr + k);
		*(arr + k) = *(arr + min);
		*(arr + min) = temp;
	}
}
double average(int* arr, int num)
{
	int total=0;
	double ave;
	for (int i = 0; i < num; i++)
	{
		total += *(arr + i);
	}
	ave = total / (double)num;
	return ave;
}
double median(int* arr, int num)
{
	double med;
	if (num % 2 == 0)
	{
		int mid1 = num / 2;
		int mid2 = num / 2 - 1;
		med = (*(arr + mid1) + *(arr + mid2)) / 2.0;
	}
	else
		med = *(arr + num/2);
	return med;
}
int mode(int* arr, int num)
{
	int* p = arr;
	int mode = -1;//众数
	int modefreq = 0;//众数出现的次数
	int currentfreq = 1;//当前轮中某个数出现的次数
	p++;
	while (p < arr + num)
	{
		if (*p == *(p - 1))
		{
			currentfreq++;
			if (currentfreq > modefreq)
			{
				mode = *p;
				modefreq = currentfreq;
			}
		}
		else
		{
			currentfreq = 1;
		}
		p++;
	}
	if (modefreq == 1)
		return -1;
	else
		return mode;
}
