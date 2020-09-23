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
    //cout<<"Am pus "<<n<<endl;
}

int pop(stiva *&top)
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

int lung(stiva *p)
{
    int nr=0;
    while(p!=NULL)
    {
        nr++;
        p=p->next;
    }
    return nr;
}

int main()
{
    int n,nr=1,x;
    cin>>n;
    if(n%2==0)
    {
        cin>>x;
        push(x);
        for(int i=1; i<n; i++)
        {
            int y;
            cin>>y;
            push(y);
            nr++;
            if(x==y)
            {
                pop(top);
                nr--;
                pop(top);
                nr--;
                if(nr==0)
                {
                    top=new stiva();
                    x=0;
                }
                else x=top->info;

            }
            else x=y;
        }
        if(nr==0) cout<<"Solutie valida";
        else cout<<"Solutie invalida";
    }
    else cout<<"n trebuie sa fie par";
    return 0;
}
