#include<stdio.h>
int main()
{
	int num[10];
	void input(int num[10], int n);
	void swap(int num[10], int n);
	void output(int num[10], int n);

	printf("Enter 10 numbers:\n");
	input(num, 10);
	swap(num, 10);
	output(num, 10);
	return 0;
}

void input(int num[10], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf_s("%d", &num[i]);
}

void swap(int num[10], int n)
{
	int i, j, temp1, temp2;
	int *min, *max;
	min = &num[0];
	for (i = 1; i < n; i++)
	{
		if (num[i] < *min)
		{
			min = &num[i];
		}
		else continue;
	}
	temp1 = num[0];
	num[0] = *min;
	*min = temp1;

	max = &num[0];
	for (j = 1; j < n; j++)
	{
		if (num[j] > *max)
		{
			max = &num[j];
		}
		else continue;
	}
	temp2 = num[9];
	num[9] = *max;
	*max = temp2;
}
void output(int num[10], int n)
{
	int i;
	printf("The order is:");
	for (i = 0; i<n; i++)
		printf("%d  ", num[i]);
}