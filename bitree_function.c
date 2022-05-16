#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char String[100];
String str;

//将扩展序列整体存储
Status StrAssign(String T, char *chars)
{
    int i;
    T[0] = strlen(chars);
    for (i = 1; i <= T[0]; i++)
        T[i] = *(chars + i - 1);
    return OK;
}

typedef char TElemType;
TElemType Nil = ' ';
Status visit(TElemType e)
{
    printf("%c ", e);
    return OK;
}

/* 结点结构 */
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//初始化
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}
//清空
void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)
            DestroyBiTree(&(*T)->lchild);
        if ((*T)->rchild)
            DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

//建立二叉树
int treeIndex = 1;
void CreateBiTree(BiTree *T)
{
    TElemType ch;

    // scanf("%c",&ch);
    ch = str[treeIndex++];
    if (ch == '.')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
//检测是否为空
Status BiTreeEmpty(BiTree T)
{
    if (T)
        return FALSE;
    else
        return TRUE;
}

//前序
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//中序
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}
//后序
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

//打印二叉树
void PrintBitree(BiTree T, int nlayer)
{
    if (T == NULL)
        return;
    PrintBitree(T->rchild, nlayer + 1);
    for (int i = 0; i <= nlayer; i++)
        printf("   ");
    printf("%c\n", T->data);
    PrintBitree(T->lchild, nlayer + 1);
}
//查询叶子节点
int LeafSeek(BiTree T)
{
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    return LeafSeek(T->lchild)+LeafSeek(T->rchild);
}
int main()
{
    BiTree T;
    InitBiTree(&T);
    StrAssign(str, "ABDH.K...E..CFI...G.J..");
    CreateBiTree(&T);
    PrintBitree(T, 1);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    int n=LeafSeek(T);
    printf("%d",n);
    getchar();
    return 0;
}