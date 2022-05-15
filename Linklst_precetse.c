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
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList; //节点的定义

Status InitList(LinkList *l) //链表的初始化
{
    *l = (LinkList)malloc(sizeof(Node));
    if (!(*l))
        return ERROR;
    (*l)->next = NULL;
    return OK;
}

Status ListEmpty(LinkList l) //判断是否为空表0.
{
    if (l->next)
        return FALSE;
    else
        return TRUE;
}

int ListLength(LinkList l) //计算链表的长度
{
    LinkList p;
    p = l->next;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

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

Status ClearList(LinkList *l) //清理链表
{
    LinkList p, q;
    p = (*l)->next;
    while (p->next)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*l)->next = NULL;
    return OK;
}

int LocateElem(LinkList l, int e) //在链表中查找一个元素，返回其位
{
    LinkList p;
    p = l->next;
    int count = 1;
    while (p)
    {
        if (p->data == e)
            return count;
        p = p->next;
        count++;
    }
    return 0;
}

Status ListInsert(LinkList *l, int i, ElemType e) //在i位插入一个元素
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
    q->next = p->next;
    p->next = q;

    return OK;
}

Status ListDelete(LinkList *l, int i, ElemType *e) //在i位删除一个元素
{
    LinkList p, q;
    p = (*l);
    int j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!(p->next)||j>i)
        return ERROR;
    q=p->next;
    p->next=p->next->next;
    *e = q->data;
    free(q);
    return OK;
}

Status ListTraverse(LinkList l)//输出链表
{
    LinkList p;
    p=l->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L);
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e);
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); 
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 
    getchar();
    return 0;
}