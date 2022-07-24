#include <iostream>
#define MAX_SIZE 100
using namespace std;
typedef struct {
    int* data;
    int len;
}List;
bool Insert(List& list,int position,int elem);
bool Delete(List& list, int position);
bool IncreaseSize(List& list, int len);//扩容
int main()
{
    int inElem, dePosition,lenth,inPosition;
    List list;
    list.data = (int*)malloc(sizeof(int) * MAX_SIZE);  
    cout << "请输入创建的长度：";
    cin >> list.len;
    cout << "请输入要插入的元素：";
    cin >> inElem;
    cout << "请输入插入的位置";
    cin >> inPosition;
    cout << "请输入要删除的位置";
    cin >> dePosition;
    for (int i = 0; i<list.len; i++)
        list.data[i] = i + 1;
    Insert(list, inPosition, inElem);
    for (int i = 0; i < list.len; i++)
        cout <<"  "<< list.data[i];
    cout << endl;
    if (Delete(list, dePosition))
        for (int i = 0; i < list.len; i++)
            cout << "  "<< list.data[i] ;
    else
        cout << "false";
    
    free(list.data);
    return 0;
}

bool Insert(List& list,int position,int elem)
{
    if (position > list.len || position < 1||position>=MAX_SIZE)
        return false;
    for (int i = list.len; i >=position; i--)
        list.data[i] = list.data[i - 1];
    list.data[position - 1] = elem;
    list.len++;
    return true;
}

bool Delete(List& list, int position)
{
    if (position > list.len || position < 1)
        return false;
    for (int i = position-1; i < list.len; i++)
        list.data[i] = list.data[i + 1];
    list.len--;
    return true;
}
