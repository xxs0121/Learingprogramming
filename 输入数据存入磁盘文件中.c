#include<stdio.h>
#define SIZE 10
struct Student_type                  //定义结构体类型
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[SIZE];

void save()                         //定义save函数
{
	FILE *fp;                       //定义指向FILE类型文件的指针变量
	int i;
	if ((fp = fopen("stu.dat", "wb")) == NULL)            //打开输出文件stu.dat
	{
		printf("cannot open file\n");
		return;
	}
	for (i = 0; i < SIZE; i++)          //执行循环，把从stud[0]所在地址开始的存储区中的数据向fp所指向的文件输出（每一次向文件输出一个结构体的数据）
		if (fwrite(&stud[i], sizeof(struct Student_type), 1, fp) != 1)       //一次写入一个数据项，一次写入sizeof(struct Student_type)个字节
			printf("file write error!\n");                    //若输入失败，在屏幕上输出警告
	fclose(fp);                                 //关闭文件
}

int main()
{
	int i;
	printf("Please enter data of students:\n");
	for (i = 0; i < SIZE; i++)                      //执行循环给结构体输入数据
		scanf("%s%d%d%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
	save();                    //调用save函数
	return 0;
}
