#include<stdio.h>
struct Student
{
	int num;
	float score;
	struct Student *next;
};
int main()
{
	struct Student a, b, c, *head, *p;    //定义3个结构体变量a,b,c作为链表的结点
	a.num = 10101; a.score = 89.5;
	b.num = 10103; b.score = 90;
	c.num = 10107; c.score = 85;
	head = &a;          //将结点a的地址赋给头指针head
	a.next = &b;        //将结点b的起始地址赋给a结点的next成员
	b.next = &c;        //将结点c的起始地址赋给b结点的next成员
	c.next = NULL;      //c结点的的成员next不再存放其他结点的地址，而存放NULL，不再指向任何有用的储存单元
	p = head;           //使p指向head，即a结点
	do
	{
		printf("%ld %5.1f\n", p->num, p->score);     //输出p当前所指向的结点的数据
		p = p->next;                                 //使p指向下一个结点
	} while (p != NULL);                             //输出c结点后，p的值为NULL，循环终止
	return 0;
}