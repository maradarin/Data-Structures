#include <iostream>

using namespace std;

struct coada
{
    int info;
    coada *prev, *next;
}*start, *fin;

void pushl(int x)
{
    coada *p = new coada();
    p->info=x;
    if (start == NULL)
        fin = start = p;
    else
    {
        p->next = start;
        start->prev = p;
        start = p;
    }
}

void pushr(int x)
{
    coada *p = new coada();
    p->info=x;
    if (fin == NULL && start==NULL)
        start = fin = p;
    else
    {
        p->prev = fin;
        fin->next = p;
        fin = p;
    }
}

int popl()
{
    coada *p = start;
    int result=p->info;
    start = start->next;
    if (start == NULL)
        fin = NULL;
    else
        start->prev = NULL;
    delete p;
    return result;
}

int popr()
{
    coada *p = fin;
    int result=p->info;
    fin = fin->prev;
    if (fin == NULL)
        start = NULL;
    else
        fin->next = NULL;
    delete p;
    return result;
}


int main()
{
    pushl(1); pushr(2);
    cout<<popr()<<endl;
    cout<<popl()<<endl;
    pushr(3);
    while(start!=NULL)
    {
        cout<<start->info<<" ";
        start=start->next;
    }
    return 0;
}
