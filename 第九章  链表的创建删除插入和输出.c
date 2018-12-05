#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;

int main()
{
	struct student *creat();
	struct student *del(struct student *head, long num);
	struct student *insert(struct student *, struct student *);
	void print(struct student *);
	struct student *head, stu;
	long del_num;
	printf("input records : \n");
	head = creat();                //调用creat函数，主函数的结构体指针head获得creat函数返回的指针head，此步骤没有向creat函数传入实参
	print(head);                  //调用print函数，实参为结构体指针head
	printf("input the deleted numbers :");
	scanf_s("%ld", &del_num);     //输入要删除的结点中num成员值，赋给del_num
	head = del(head, del_num);    //将主函数中的头指针head和del_num作为实参传入del函数
	print(head);                  //调用print函数，将头指针head作为实参传入，头指针指向整个链表的起始地址
	printf("input the inserted record :");       //输入要插入的结点成员值
	scanf_s("%ld,%f", &stu.num, &stu.score);     //将值赋给结构体变量stu
	head = insert(head, &stu);                   //insert传回新的链表头指针
	print(head);                                 //调用print函数输出新链表
	return 0;
};


struct student *creat()
{
	struct student *head;
	struct student *p1, *p2;
	n = 0;
	p1 = p2 = (struct student *)malloc(LEN);
	scanf_s("%ld,%f", &p1->num, &p1->score);    //为p1结点赋初值，进入下面的while循环
	head = NULL;                        //先使头指针指向NULL，不指向结点
	while (p1->num != 0)          //读取的p1结点中的num成员的值不为0则继续本次循环
	{
		n = n + 1;               //用于统计创建的结点个数
		if (n == 1)              //判断p1是否是第一个结点
			head = p1;        //p1是第一个结点，头指针指向p1
		else
			p2->next = p1;    //p2所指向的结点的next成员指向p1，即使p1所指向的结点连接在p2所指向的结点后面
		                      //（p1指向新开辟的结点，p2指向链表最后的结点）	
		p2 = p1;              //将p1结点起始地址赋给p2，使p2拥有原先p1的地址
		p1 = (struct student *)malloc(LEN);  //为新的p1所指向的结点开辟内存空间
		scanf_s("%ld,%f", &p1->num, &p1->score);   //读取数据赋给p1所指向的结点
	}
	p2->next = NULL;    //p2所指向的结点的next成员值为NULL，即p2不再指向新的结点
	return(head);  //返回头指针，带回链表起始地址
};

struct student *del(struct student *head, long num)
{
	struct student *p1;              
    struct student *p2=NULL;
	if (head == NULL)                       //如果头指针指向NULL，即链表为空，则输出错误提示
	{
		printf("\nlist null! \n");
		return(head);
	}
	p1 = head;                             //p1获得传入的链表起始地址，此时p1表示第一个结点
	while (num != p1->num&&p1->next != NULL)    //若传入的要删除num值不为第一个结点中的num，且第二个结点非空，执行循环使p1指向下一个结点
	{
		p2 = p1;                        //p2获得p1的地址，p2指向p1
		p1 = p1->next;                  //p1指向下一个新的结点
	}
	if (num == p1->num)          //若num的值等于当前p1所指向的结点中的num，执行下面的语句
	{
		if (p1 == head)               //如果当前的p1为链表的第一个结点
			head = p1->next;           //则使head指向后面的结点（跳过当前的结点）
		else
			p2->next = p1->next;  //否则将下一个结点p1的next成员的值赋给上一个结点p2的next成员，
								  //即跳过上一个结点而指向下一个结点，上一个结点被删除
		
		printf("delete:%ld\n", num);      //输出要删除的结点的num值
		n = n - 1;                        //链表的结点数-1
	}
	else
		printf("%ld not been found ! \n", num);    //否则输出未找到该结点
	return(head);                      //将删除结点后的链表返回主函数
}

struct student *insert(struct student *head, struct student *stu)   //定义insert函数，传入实参为主函数的头指针和要插入的结点的指针
{
	struct student *p0, *p1, *p2=NULL;
	p1 = head;                                         //p1获得链表起始地址，此时p1代表第一个结点
	p0 = stu;                                          //p0获得要插入的节点的地址
	if (head == NULL)                                  //若头指针地址为空，即链表为空
	{
		head = p0;                                    //使头指针指向p0
		p0->next = NULL;                              //p0的next成员指向NULL，结束链表
	}
	else
	{
		while ((p0->num > p1->num) && (p1->next != NULL))  //当p0结点中的成员num大于p1中的num且p1后面还有结点时
		{
			p2 = p1;                                     //p2获得当前p1的地址，p2指向p1
			p1 = p1->next;                               //p1指向下一个新节点
		}
		if (p0->num <= p1->num)                          //如果p0中的num小于等于p1中的num
		{
			if (head == p1)                              //如果head所指向的地址就是p1所指向的地址，即p1结点是第一个结点
				head = p0;                               //将p0所指向的地址赋给头指针，即p0所指结点插入到p1所指结点前面
			else
				p2->next = p0;          //如果p1结点不是第一个结点，把p0的地址赋给p2中的next成员，即使p2中的next指向p0结点
			p0->next = p1;              //p0结点中的next成员指向后面的p1结点，这两步将p0插到上一个结点p2和下一个结点p1之间
		}
		else                  //p0中的num大于p1中的num且p1为链表最后一个结点时
		{
			p1->next = p0;        //使p1中的next指向p0
			p0->next = NULL;      //使p0中的next指向NULL，结束链表。这两部将p0作为链表最后一个结点而结束链表
		}
	}
	n = n + 1;                      //链表结点总数+1
	return(head);                   //返回当前链表
}


void print(struct student *head)            //声明print函数，形参为结构体指针
{
	struct student *p;                        //定义结构体指针p
	printf("\nNow,These %d records are :\n", n);
	p = head;                                //p指向传入的实参head，即链表头指针，获取整个链表的初始地址
	if (head != NULL)                           //如果链表非空，执行循环
		do
		{
			printf("%ld %5.1f\n", p->num, p->score);    //输出当前p所指向的结点的成员值
			p = p->next;                                //把当前结点中next成员所指向的地址赋给p，若p不是NULL继续循环
		} while (p != NULL);                   //当p指向结点时继续循环
}
