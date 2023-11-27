#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10
void menu();
int getstudentnum();//观影学生人数
void getmoviedata(int [],int );//观影信息
void sort(int[], int);//排序
double average(int [],int );//平均数
double median(int [],int );//中位数
int mode(int[], int);//众数
void display(int[], int);//显示统计结果
int main()
{
	int moviedata[N];//保存每个人的观影次数
	int input = 0;
	int num = 10;//默认学生人数
	do {
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			num = getstudentnum();//读取参与调研的人数
			break;
		case 2:
			getmoviedata(moviedata,num);//读取电影信息
			sort(moviedata, num);//排序，方便后续统计功能的执行
			break;
		case 3:
			display(moviedata,num);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，重新选择>\n");
			break;
		}

	} while (input);
	return 0;
}
void menu()
{
	printf("*******************************************\n");
	printf("*** 1.input student number            *****\n");
	printf("*** 2.input movie-viewing data        *****\n");
	printf("*** 3.display statistical information *****\n");
	printf("*** 0.exit  *******************************\n");
	printf("*******************************************\n");
}
int getstudentnum()
{
	int num;
	printf("输入参与调研的学生人数>");
	scanf("%d", &num);
	return num;
}
void getmoviedata(int arr[], int num)
{
	printf("请输入每个学生观看的电影数目>");
	for (int i = 0; i < num; i++)
	{
		printf("student%d", i + 1);
		scanf("%d", &arr[i]);
	}
}
void sort(int arr[], int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
double average(int arr[], int num)
{
	int sum = 0;
	double ave;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	ave = sum / (double)num;
	return ave;
}
double median(int arr[], int num)
{
	double med;
	if (num % 2 == 0)
	{
		int mid1 = num/2,mid2 = (num/2)-1;
		med = (arr[mid1]+arr[mid2])/2.0;
	}
	else
		med = arr[num/2];
	return med;
}
int mode(int arr[], int num)
{
	int mode = -1;
	int p = 1;
	int modefreq = 0;//众数出现的次数
	int count = 1;//当前轮中某个数出现的次数
	while (p < num)
	{
		if (arr[p] == arr[p - 1])
		{
			count++;
			if (count > modefreq)
			{
				mode = arr[p];
				modefreq = count;
			}
		}
		else
		{
			count = 1;
		}
		p++;
	}
	if (modefreq == 1)
		return -1;
	else
		return mode;
}
void display(int arr[], int num)
{
	printf("电影数据：\n");
	for (int i = 0; i < num; i++)
	{
		printf("%8d ", arr[i]);
	}
	printf("\n");
	printf("film stat:\n");
	printf("%6s%g\n", "average: ", average(arr, num));
	printf("%6s%g\n", "median: ", median(arr, num));
	int m = mode(arr, num);
	printf("%6s%d\n", "mode: ", (m == -1? 0 : m));
}
