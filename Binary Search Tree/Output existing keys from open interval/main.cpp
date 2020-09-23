#include <iostream>
using namespace std;

struct arbore
{
    int info;
    arbore *st, *dr;
} *r;

arbore* newarb(int key)
{
    arbore* node = new arbore;
    node->info = key;
    node->st = node->dr = NULL;
    return node;
}

arbore* inserare(arbore* r, int key)
{
    if (r == NULL) return newarb(key);
    if (key < r->info) r->st = inserare(r->st, key);
    else r->dr = inserare(r->dr, key);
    return r;
}

int caut(int x, arbore* r)
{
    arbore *p=r;
    while(p!=NULL)
    {
        if(p->info==x) return 1;
        if(p->info<x) p=p->dr;
        else p=p->st;
    }
    return 0;
}

int main()
{
    int n,k1,k2;
    cin>>n;
    r=NULL;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        r=inserare(r,x);
    }
    cin>>k1>>k2;
    for(int i=k1+1;i<k2;i++)
        if(caut(i,r)==1) cout<<i<<" ";
    return 0;
}
