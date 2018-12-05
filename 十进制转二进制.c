#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	long num;
	int i, j;
	printf("Input number:");
	scanf_s("%d", &num);
	if (num == 1)
		printf("The binary number is:%d", num);
	else if (num > 1)
	{
		for (i = 0; i<100; i++)
		{
			if (num>=pow(2, i))
			{
				j = i + 1;
			}
			else
				continue;
		}
		int *p;
		p = (long *)malloc(j * sizeof(long));
		for (i = 0; i<j; i++)
		{
			if (num>1)
			{
				*(p + i) = num % 2;
				num = num / 2;
			}
			else if (num == 1)
				*(p + i) = num;
		}
		printf("The binary numbers are:");
		for (i = 0; i < j; i++)
		{
			printf("%d ", *(p + j - i - 1));
			if ((i + 1) % 4 == 0 && i + 1 < j)
				printf(".");
		}
		printf("\n");
	}
	return 0;
}
