#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "string.h"
#include "ctype.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef double ElemType;
typedef struct Node
{
    ElemType data;
    char name[9];
    struct Node *next;
} Node;
typedef struct Node *LinkList; //节点的定义
Status GetElem(LinkList l, int n, ElemType *e) //输出第n数据
{
    LinkList p;
    p = l->next;
    int i = 1;
    while (p && i < n)
    {
        p = p->next;
        i++;
    }
    if (!p || i > n)
        return ERROR;
    *e = p->data;
    return OK;
}
Status InitList(LinkList *l) //链表的初始化
{
    *l = (LinkList)malloc(sizeof(Node));
    if (!(*l))
        return ERROR;
    (*l)->next = NULL;
    return OK;
}
Status ListInsert(LinkList *l, int i, ElemType e,char a[9]) //在i位插入一个元素
{
    LinkList p, q;
    p = *l;
    int j = 1;
    while (p && j < i)
    {
        j++;
        p = p->next;
    }
    if (!p || j > i)
        return ERROR;
    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    strcpy(q->name,a);
    q->next = p->next;
    p->next = q;
    return OK;
}
void sort_list(LinkList l)
{
	LinkList pre,  p,  q;
	LinkList tail = NULL;
	while (l->next != tail)
	{						 					
		pre = l;
		p = l->next;
		q = p->next;
		while (p->next != tail)
		{
			if (p->data < q->data)
			{	
				pre->next = q;
				p->next = q->next;
				q->next = p;
			}
			else
			{
				p = p->next;
			}
			q = p->next;
			pre = pre->next;
		}
		tail = p;
	}
}
Status ListTraverse(LinkList l)//输出链表
{
    LinkList p;
    p=l->next;
    int i=0;
    while(p)
    {
        i++;
        printf(" %2d \t%s\t %.2f \n",i,p->name,p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
int main()
{
    double Gdp_data[31] = {42959.2, 40269.6, 48810.36, 10243.3, 124369.67, 24740.86, 19586.42,
                        6475.2, 40391.3, 58887.41, 14879.2, 50012.94, 46063.09, 13235.52,
                        116364.2, 29619.7, 27584.1, 20514.2, 4522.31, 3346.63, 83095.9,
                        22590.16, 29800.98, 43214.85, 53850.79, 15695.05, 2080.17, 15983.65,
                        27146.76, 73516, 27894.02};
    char Province_name[31][9]={{"安徽"},{"北京"}, {"福建"}, {"甘肃"}, {"广东"},{ "广西"},{ "贵州"},{"海南"}, 
                            {"河北"}, {"河南"}, {"黑龙江"}, {"湖北"}, {"湖南"}, {"吉林"}, {"江苏"}, {"江西"}, 
                            {"辽宁"}, {"内蒙古"}, {"宁夏"}, {"青海"}, {"山东"}, {"山西"}, {"陕西"},{"上海"}, 
                            {"四川"}, {"天津"}, {"西藏"}, {"新疆"}, {"云南"}, {"浙江"}, {"重庆"}} ;
    LinkList Province_GDP;
    InitList(&Province_GDP);
    for(int i=1;i<=31;i++)
        ListInsert(&Province_GDP,i,Gdp_data[i-1],Province_name[i-1]);
    sort_list(Province_GDP);
    ListTraverse(Province_GDP);
    getchar();
    return 0;
}