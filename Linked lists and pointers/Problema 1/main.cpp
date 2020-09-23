#include <iostream>

using namespace std;

struct stiva
{
    int info;
    stiva *next;
} *top;

void push(int n)
{
    stiva *p=new stiva();
    p->info=n;
    p->next=top;
    top=p;
    cout<<"am pus"<<endl;
}

int pop()
{
    if (top == NULL)
        return -1;
    stiva *p = top;
    int result = top->info;
    top = top->next;
    p->next=NULL;
    delete p;
    return result;
}

int main()
{
    push(1); push(2); cout<<pop()<<endl ; push(3);
    return 0;
}
