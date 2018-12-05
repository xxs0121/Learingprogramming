#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	struct student *next;
};

struct student *list_a, *list_b;
int n, sum_a = 0, sum_b = 0;

int main()
{
	struct student *head;
	struct student *create_a(void);
	struct student *create_b(void);
	struct student *combine(struct student *list_a, struct student *list_b);
	void print(struct student *head);
	printf("input list a:\n");
	list_a = create_a();
	if (list_a != NULL)
	{
		printf("input list b:\n");
		list_b = create_b();
	}
	head = combine(list_a,list_b);
	print(head);
	return 0;
}

struct student *create_a(void)
{
	struct student *p1 = NULL, *p2 = NULL, *head = NULL;
	n = 0;
	p1 = p2 = (struct student *)malloc(LEN);
	scanf_s("%ld,%f", &p1->num, &p1->score);
	while (p1->num != 0)
	{
		sum_a = sum_a + 1;
		if (sum_a == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		scanf_s("%ld,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return(head);
}

struct student *create_b(void)
{
	struct student *p1 = NULL, *p2 = NULL, *head = NULL;
	n = 0;
	p1 = p2 = (struct student *)malloc(LEN);
	scanf_s("%ld,%f", &p1->num, &p1->score);
	while (p1->num != 0)
	{
		sum_b = sum_b + 1;
		if (sum_b == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		scanf_s("%ld,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return(head);
}

struct student *combine(struct student *list_a, struct student *list_b)
{
	struct student *pa1 = NULL, *pa2 = NULL, *pb1 = NULL, *pb2 = NULL;    //定义结构体指针
	pa1 = pa2 = list_a;                                                   //使pa1 pa2指向链表list_a，获得链表中的第一个结点地址
	pb1 = pb2 = list_b;
	do                        //当pa1的下一个结点非空，或者pa1为空且pb1非空时，执行循环
	{
		while ((pb1->num > pa1->num) && (pa1->next != NULL))//当pb1中的num大于pa1中的num且pa1下一个结点非空时执行循环
		{
			pa2 = pa1;               //pa2获得当前pa1的地址
			pa1 = pa1->next;         //pa1指向下一个结点
		}
		if (pb1->num <= pa1->num)    //pb1中的num小于等于pa1中的num时执行循环
		{
			if (list_a == pa1)       //若lista_a链表头指针与pa1指针的值相等（指向同一个地址）（pa1指向链表头结点）
				list_a = pb1;        //pb1指针的值赋给list_a头指针（使二者指向相同）   （这两步使pb1取代pa1成为链表第一个结点）
			else                     //pa1不指向链表头结点时
				pa2->next = pb1;    //将pb1的值赋给pa2中的next元素，即使list_a中的上一个结点pa2中的next元素指向list_b的pb1结点（pb1结点接在pa2后，在pa1前）
			pb2->next = pa1;     //pa1结点接在pb2结点后
			pa2 = pb2;          //pb2的值赋给pa2，pa2拥有原先pb2的地址
			pb2 = pb1;          //pb1的值赋给pb2，pb2拥有原先pb1的地址，pa1结点接在pb1后。以上四步构成pa2 pb2 pb1 pa1顺序
		}
	}while ((pa1->next != NULL) || (pa1 == NULL && pb1 != NULL));   //pa1后非空或pa1为空，pb1非空
	if ((pb1 != NULL) && (pb1->num > pa1->num) && (pa1->next == NULL))  //pb1不为空，且pb1中的num大于pa1中的num且pa1后面结点为空
		 pa1->next = pb1;     //将pb1接在pa1后
	return(list_a);   //返回list_a链表的头指针
}

void print(struct student *head)
{
	struct student *p = head;
	printf("\nThe combined list is :\n");
	if (head != NULL)
		do
		{
			printf("%ld,%f\n", p->num, p->score);
			p = p->next;
		} while (p !=NULL);
}
