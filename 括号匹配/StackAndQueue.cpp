#include <iostream>
#include <stack>
#define MaxSize 30
using namespace std;
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];//存放栈的静态数组
    int top;//栈顶指针，即栈顶元素所在位置
}SqStack;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
}LinkNode, * LinkStack;
typedef struct Queue{
    ElemType data[MaxSize];//存放队列元素的静态数组
    int front = 0,rear = 0;//分别表示队头指针和队尾指针，初始位置均为0
    int length = 0;//存储队列当前的元素个数
}Queue;

typedef struct {
    LinkNode* front, * rear;//队头指针和队尾指针
}LinkQueue;

void bracketCheck(const char[],int length);
bool isCheck(char a, char b);
int main()
{
    bracketCheck("{(())[]}",8);
    bracketCheck("{(()][]}", 8);
    bracketCheck("{(())}]()", 9);
    bracketCheck("{{(())[]}", 9);
}

void bracketCheck(const char str[], int length)
{
    stack<char> left_bracket;
    for (int i = 0; i < length; i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            left_bracket.push(str[i]);
        }
        else {
            if (left_bracket.empty())
            {
                cout << "wrong2" << endl;
                return;
            }
            if (isCheck(left_bracket.top(),str[i]))
            {
                left_bracket.pop();
            }
            else
            {
                cout << "wrong1"<<endl;
                return;
            }
        }
        /*
        if (left_bracket.empty()&&i<length-1)
        {
            cout << "wrong2" << endl;
            return;
        }
        */
    }
    if (left_bracket.empty())
        cout << "啊对对对" << endl;
    else
        cout << "worng3" << endl;
}
bool isCheck(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return true;
    else
        return false;
}