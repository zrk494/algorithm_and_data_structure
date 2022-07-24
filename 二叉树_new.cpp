#include <iostream>
#include <queue>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode* left, * right;
}BiTNode,*BiTree;
typedef struct ThreadNode {
    char data;
    struct ThreadNode* lchild, * rchild;
    bool ltag, rtag;//标识是否是左右线索，false表示其指向一个孩子
}ThreadNode, * ThreadTree;
void initTree(BiTree& T);
void PreOrder(BiTree T);//先当前结点，再左孩子，再右孩子
void InOrder(BiTree T);//先左孩子，再父结点，再右孩子
void PostOrder(BiTree T);//先左孩子，再右孩子，再父结点
void CreateInThread(ThreadTree T);
void InThread(ThreadTree T, ThreadNode*& pre);
int main()
{
    BiTree tree = NULL;
    initTree(tree);
    cout << "PreOrder" << endl;
    PreOrder(tree);
    cout << endl << "InOrder" << endl;
    InOrder(tree); 
    cout << endl << "PostOrder" << endl;
    PostOrder(tree);
    cout << endl << "ThreadTree" << endl;
    ThreadTree t_tree = (ThreadTree)tree;
    
    CreateInThread(t_tree);

    return 0;
}

void initTree(BiTree& T)
{
    BiTNode* p_node;
    BiTNode* current_node;
    queue<BiTNode*> my_queue;
    char ch;
    while (scanf("%c",&ch)!=EOF)
    {
        if (ch == '\n')
            break;
        p_node = (BiTNode*)malloc(sizeof(BiTNode));
        p_node->left=NULL;
        p_node->right=NULL;
        p_node->data = ch;
        my_queue.push(p_node);
        if (T==NULL)
        {
            T = p_node;
            continue;
        }
        current_node = my_queue.front();
        if (my_queue.front()->left == NULL) {
            my_queue.front()->left = p_node;
        }
        else if (my_queue.front()->right == NULL)
        {
            my_queue.front()->right = p_node;
            my_queue.pop();
        }
    }
}
void PreOrder(BiTree T)
{
    if (T != NULL) {
        cout << T->data;
        PreOrder(T->left);
        PreOrder(T->right);
    }
}
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data;
        InOrder(T->right);
    }
}
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        cout << T->data;
    }
}
void CreateInThread(ThreadTree T) {
    ThreadNode* pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
void InThread(ThreadTree T, ThreadNode*& pre) {
    if (T != NULL) {
        InThread(T->lchild, pre);
        if (T->lchild == NULL) {
            T->lchild = pre;
            T->ltag = 1;
        }
        if (pre != NULL && T->rchild == NULL)
        {
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->rchild, pre);
    }
}