#include<stdio.h>
#include<string.h>
int main()
{
	void sort(char *[]);
	int i;
	char *p[10], str[10][10];
	for (i = 0; i < 10; i++)
		p[i] = str[i];
	printf("input 10 strings:\n");
	for (i = 0; i < 10; i++)
		scanf_s("%s", p[i],10);
	sort(p);
	printf("the sorted strings :\n");
	for (i = 0; i < 10; i++)
		printf("%s\n", p[i]);
	return 0;
}
void sort(char*s[])
{
	int i, j;
	char *tp;
	for (i = 0; i < 9; i++)
		for (j = i+1; j < 10; j++)
		{
			if (strcmp(*(s + i), *(s + j)) > 0)
			{
				tp = *(s + j);
				*(s + j) = *(s + i);
				*(s + i) = tp;
			}
		}
}