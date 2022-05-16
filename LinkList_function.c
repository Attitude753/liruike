#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "time.h"
#include "string.h"

#define error 0
#define ok 1

typedef int status;
typedef int unit;

typedef struct Node //定义单向节点
{
    unit data;
    struct Node *next;
} Node;
typedef Node *linklist;

typedef struct Node_duplex //双向节点
{
    struct Node_duplex *back;
    unit data;
    struct Node_duplex *next;
} Node_duplex;
typedef Node_duplex *linklist_duplex;

//单向链表初始化
status linklist_initialize(linklist *list)
{
    *list = (linklist)malloc(sizeof(Node));
    if (!(*list))
        return error;
    (*list)->next = NULL;
    return ok;
}

//双向链表初始化
status linklist_duplex_initialize(linklist_duplex *list)
{
    *list = (linklist_duplex)malloc(sizeof(Node_duplex));
    if (!(*list))
        return error;
    (*list)->next = (*list);
    (*list)->back = (*list);

    return ok;
}

//检测链表是否为空，单向链表
status linklist_check(linklist list)
{
    if (list->next)
        return error;
    else
        return ok;
}

//检测链表是否为空，双向链表
status linklist_duplex_check(linklist_duplex list)
{
    if (list->next != list)
        return error;
    else
        return ok;
}

//清空链表，单项链表
status linklist_clean(linklist *list)
{
    linklist temp_list = *list, temp;
    while (temp_list->next)
    {
        temp = temp_list->next;
        free(temp_list);
        temp_list = temp;
    }
    return ok;
}

//清理链表，双向链表
status linklist_duplex_clean(linklist_duplex *list)
{
    linklist_duplex temp_list = *list, temp;
    while (temp_list->next != temp_list)
    {
        temp = temp_list->next;
        free(temp_list);
        temp_list = temp;
    }
}

//在第n位插入一个节点，包括该节点的数据,单向链表
status linklist_insert(linklist *lisk, int n, unit data)
{
    linklist templist = *lisk, newlist;
    int i = 1;
    while (i < n && templist)
    {
        i++;
        templist = templist->next;
    }
    if (!templist || i > n)
        return error;
    newlist = (linklist)malloc(sizeof(Node));
    newlist->data = data;
    newlist->next = templist->next;
    templist->next = newlist;
    return ok;
}

//在第n位插入一个节点，包括该节点的数据,双向链表
status linklist_duplex_insert(linklist_duplex *list, int n, unit data)
{
    linklist_duplex templist = *list, newlist;
    int i = 1;
    while (i < n && templist->next != (*list))
    {
        i++;
        templist = templist->next;
    }
    if (i > n)
        return error;
    newlist = (linklist_duplex)malloc(sizeof(Node_duplex));
    newlist->data = data;
    newlist->next = templist->next;
    newlist->back = templist;
    templist->next->back = newlist;
    templist->next = newlist;
    return ok;
}

//在第n位删除一个节点，单向链表
status linklist_delete(linklist *list, int n)
{
    linklist templist = *list, temp;
    int i = 1;
    while (i < n && templist)
    {
        i++;
        templist = templist->next;
    }
    if (!templist || i > n)
        return error;
    temp = templist->next;
    templist->next = temp->next;
    free(temp);
    return ok;
}

//在第n位删除一个节点，双向链表
status linklist_duplex_delete(linklist_duplex *list, int n)
{
    linklist_duplex templist = *list, temp;
    int i = 1;
    while (i < n && templist->next != (*list))
    {
        i++;
        templist = templist->next;
    }
    if ((templist == (*list)) || i > n)
        return error;
    temp = templist->next;
    temp->next->back = templist;
    templist->next = temp->next;
    free(temp);
    return ok;
}

//查找链表中的一个元素，返回其位置，单向链表
int linklist_seek_unit(linklist *list, unit data)
{
    linklist templist = (*list)->next, temp;
    int i = 0;
    while (templist)
    {
        i++;
        if (templist->data == data)
            return i;
        templist = templist->next;
    }
    if (!templist)
        return error;
}

//查找链表中的一个元素，返回其位置，双向链表
int linklist_duplex_seek_unit(linklist_duplex *list, unit data)
{
    linklist_duplex templist = (*list)->next, temp;
    int i = 0;
    while (templist)
    {
        i++;
        if (templist->data == data)
            return i;
        templist = templist->next;
    }
    if (!templist)
        return error;
}

//输出（打印）一个节点的数据
status node_output(unit data)
{
    printf("%2d", data);
    return ok;
}
//从第一个节点到最后一个节点输出整个链表,单向链表
status linklist_output(linklist *list)
{
    linklist templist = (*list)->next;
    while (templist)
    {
        node_output(templist->data);
        templist = templist->next;
    }
    printf("\n");
    return ok;
}

//从第一个节点到最后一个节点输出整个链表,双向链表
status linklist_duplex_output(linklist_duplex *list)
{
    linklist_duplex templist = (*list)->next;
    while (templist != (*list))
    {
        node_output(templist->data);
        templist = templist->next;
    }
    printf("\n");
    return ok;
}

//输出链表第n位的数据，单向链表
status linklist_unitoutput(linklist *list, int n)
{
    linklist templist = (*list)->next;
    int count = 0;
    while (templist)
    {
        count++;
        if (count == n)
            node_output(templist->data);
        templist = templist->next;
    }
    if (!templist || n > count)
        return error;
    return ok;
}

//输出链表第n位的数据，双向链表
status linklist_duplex_unitoutput(linklist_duplex *list, int n)
{
    linklist_duplex templist = (*list)->next;
    int count = 0;
    while (templist!=(*list))
    {
        count++;
        if (count == n)
            node_output(templist->data);
        templist = templist->next;
    }
    if (!templist || n > count)
        return error;
    return ok;
}

//双向链表交换节点
status node_duplex_swap(int i,int j,linklist_duplex *list)
{
    
}

int main()
{
    //单向链表
    unit data[10];
     for (int i = 0; i <= 9; i++)
         data[i] = i;
     linklist onelist;
     linklist_initialize(&onelist);
     int outcome = linklist_check(onelist);
     printf("%d \n", outcome);
     for (int i = 0; i <= 9; i++)
         linklist_insert(&onelist, i+1,data[i]);
     linklist_output(&onelist);
     for (int i = 0; i <= sizeof(data) / sizeof(data[0]); i++)
         linklist_unitoutput(&onelist, i + 1);
     printf("%d");
     linklist_delete(&onelist, 7);
     linklist_output(&onelist);
     int site=linklist_seek_unit(&onelist, 3);
     printf("%d",site);
     linklist_clean(&onelist);
     linklist_initialize(&onelist);
     outcome = linklist_check(onelist);
     printf("%d \n", outcome);
    

    //双向链表
    unit data2[10];
    for (int i = 0; i <= 9; i++)
        data2[i] = i;
    linklist_duplex duplex;
    linklist_duplex_initialize(&duplex);
    int outcome2 = linklist_duplex_check(duplex);
    printf("%d \n", outcome2);
    for (int i = 0; i <= 9; i++)
        linklist_duplex_insert(&duplex, i + 1, data2[i]);
    linklist_duplex_output(&duplex);
    linklist_duplex_delete(&duplex, 7);
    linklist_duplex_output(&duplex);
    for(int j=1;j<=9;j++)
    linklist_duplex_unitoutput(&duplex,j);
    printf("\n");
    linklist_duplex_output(&duplex);

    getchar();
    return 0;
}