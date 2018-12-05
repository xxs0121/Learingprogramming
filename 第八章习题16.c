#include<stdio.h>
#include<math.h>
int main()
{
	char str[100];
	char *p;
	int a[100], num[100], *q;
	int h, i, j, k = 0, m, sum = 0;

	printf("输入字符串：");
	printf("\n");
	gets_s(str, 100);
	p = str;
	for (i = 0; i<100; i++)    //从第一个字符开始检查a数组的字符
	{
		if (48 <= *(p+i)&&*(p+i) <= 57)    //如果p指向的数组元素为数字，进入下一个字符的检查
		{
			q = num;               //使q指向num数组
			h = 0;                 //初始化h为0，h用于统计连续数字的个数
			for (j = i; j < 100; j++)    //从连续数字中的第一个数字开始循环，最多循环100次，将连续的数字送入num数组
			{
				if (48 <= *(p + j ) && *(p + j ) <= 57)    //如果从第i个字符开始后的字符均为数字，就将其以数字形式赋给q所指向的num数组的地址，h+1
				{
					*q = (int)(*(p + j) - 48);
					h++;
					q++;
				}
				else                         //如果不是数字，就停止循环
					break;
			}
			q = num;                     //使q重新指向num数组的首地址
			a[k] = 0;                    //对a[k]赋初值为0
			for (m = 0; m < h; m++, q++)
			{
				a[k] = a[k] + (*q) * pow(10 , h - m - 1);
			}
			k++;
			sum++;
			i = j + 1;
		}
		else
			continue;
	}
	printf("总共有%d个整数，分别为：\n", sum);
	for (i = 0; i < k; i++)
	{
		printf("%d   ", a[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}