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

void SRD(arbore *r, int niv)
{
    if(r!=NULL)
    {
        SRD(r->st,niv+1);
        cout<<r->info<<" pe nivelul "<<niv<<endl;
        SRD(r->dr,niv+1);
    }
}

void RSD(arbore *r, int niv)
{
    if(r!=NULL)
    {
        cout<<r->info<<" pe nivelul "<<niv<<endl;
        RSD(r->st,niv+1);
        RSD(r->dr,niv+1);
    }
}

arbore* minim(arbore* t)
{
    if(t == NULL) return NULL;
    else if(t->st == NULL) return t;
    else return minim(t->st);
}

arbore* sterg(int x, arbore* t, int &ok)
{
    arbore* temp;
    if(t == NULL) {ok=0; return NULL;}
    else if(x < t->info) t->st = sterg(x, t->st, ok);
    else if(x > t->info) t->dr = sterg(x, t->dr, ok);
    else if(t->st && t->dr)
    {
        temp = minim(t->dr);
        t->info = temp->info;
        t->dr = sterg(t->info, t->dr, ok);
    }
    else
    {
        temp = t;
        if(t->st == NULL) t = t->dr;
        else if(t->dr == NULL) t = t->st;
        delete temp; ok=1;
    }
    return t;
}

int main()
{
    int n,m,niv=0,ok=0;
    cout<<"Nr total de noduri "; cin>>n;
    r=NULL;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        r=inserare(r,x);
    }
    cout<<"Nr cautat si care va fi sters "; cin>>m;
    cout<<endl<<"Rezultat cautare "<<caut(m,r)<<endl<<endl;
    RSD(r,niv);
    cout<<endl; niv=0;
    SRD(r,niv);
    cout<<endl; niv=0;
    r=sterg(m,r,ok);
    if(ok==0) cout<<"Nu exista valoarea de sters";
    else SRD(r,niv);
    return 0;
}
