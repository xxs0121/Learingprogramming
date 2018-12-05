#include<stdio.h>
int main()
{
	int num[10], i;
	int *p=num;
	void sort(int *x,int n);

	for (i = 0; i<10; i++)
	{
		printf("输入数字：");
		scanf_s("%d", p++);
	}
	p = num;
	sort(p,10);
	return 0;
}
void sort(int *x, int n)
{
	int i, j = 9, a[10];
	for (i = 0; i < 10; i++, j--)
	{
		a[i] = *(x + j);
	}
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}