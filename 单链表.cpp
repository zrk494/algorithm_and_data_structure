#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;    
}*LinkList,LNode;
LinkList CreateList1(LinkList& L);//头插法建链表，输入9999结束
LinkList CreateList2(LinkList& L);//尾插法建链表，输入9999结束
void PrintList(LinkList L);//打印链表
LNode *GetItemById(LinkList L,int n);//查询链表中第n个元素，按位置查询，最终返回查询到的结点
LNode* GetItem(LinkList L, ElemType item);//按值查询，找到第一个就将这个结点返回
bool ListFrontInsert(LinkList L, int n, ElemType elem);//在第i个元素之前插入一个结点
bool ListDelete(LinkList L, int n);
int main()
{
    LinkList L1, L2;
    LNode* search1, * search2;
    
    CreateList1(L1);
    PrintList(L1);

    CreateList2(L2);
    PrintList(L2);
    
    search1 = GetItemById(L1, 2);
    search2 = GetItemById(L2, 2);

    if (search1!=NULL)
    {
        printf("L1 success");
    }
    if (search2!=NULL)
    {
        printf("L2 success");
    }
    ListFrontInsert(L1,2,4);
    PrintList(L1);
    return 0;
}
LinkList CreateList1(LinkList& L)//头插法,可以完成链表的逆置
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* s;
    ElemType dataNum;
    cin >> dataNum;
    while (dataNum!=9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = dataNum;
        s->next = L->next;
        L->next = s;
        cin >> dataNum;
    }
    return L;
}
LinkList CreateList2(LinkList& L)//尾插法
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* s, * r = L;
    ElemType dataNum;
    cin >> dataNum;
    while (dataNum!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = dataNum;
        r->next = s;
        r = r->next;
        cin >> dataNum;
    }
    r->next = NULL;
    return L;
}
void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
        if (L != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}
LNode* GetItemById(LinkList L, int n)
{
    int j = 1;
    LNode *p=L = L->next;
    if (0 == n)
        return L;//如果n为0则返回头结点
    if (n < 1) {
        return NULL;
    }//n小于0则返回空
    
    while (j<n&&L)
    {
        p = p->next;//让p指向下一个结点
        j++;
    }
    return p;
}

bool ListFrontInsert(LinkList L, int n, ElemType elem)
{

    LNode* p=GetItemById(L,n-1);//获取第i个位置结点的前一个结点（单链表只有后面元素的信息）
    if (!p)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = elem;
    s->next = p->next;
    p->next=s;
    return true;
}

bool ListDelete(LinkList L, int n)
{
    LNode* p = GetItemById(L, n - 1);
    if (!p)
        return false;
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;
    return true;
}

LNode* GetItem(LinkList L, ElemType item)
{
    LNode* p = L->next;
    while(p&&p->data!=item)
    {
        p = p->next;
    }

    return p;
}
