#include <stdio.h>
#include <stdlib.h>

struct Student_type                 //定义结构体
{
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[10];

int main()
{
    int i;
    FILE *fp;                    //定义指向FLIE类型文件的指针变量
    if((fp=fopen("stu.dat","rb"))==NULL)             //打开文件，如果打开失败则在屏幕上输出警告
    {
        printf("cannot open file\n");
        exit(0);
    }
    for(i=0;i<10;i+=2)                     //执行五次循环，i的每次增值为2
        {
            fseek(fp,i*sizeof(struct Student_type),0);       //fseek函数调用中，指定“起始点”为0，即以文件开头为参照点
                                                    //位移量为i*sizeof(struct Student_type),定位到需要输出的结构体变量的数据区的开头
            fread(&stud[i],sizeof(struct Student_type),1,fp);  //从fp所指文件读取当前定位到的结构体变量，一次读取一个数据项，一次读取
                                                               //sizeof(struct Student_type)个字节，存放在内存中的结构体数组stud[i]中
            printf("%-10s %4d %4d %-15s\n",stud[i].name,stud[i].num,stud[i].age,stud[i].addr);      //输出当前所读取的结构体变量中的数据
        }
    fclose(fp);                                                  //关闭文件
    return 0;
}
