#include <iostream>
#include <cstring>
using namespace std;


struct arbore
{
    char info[100];
    arbore *st, *dr;
} *r;

arbore* newarb(char key[100])
{
    arbore* node = new arbore;
    strcpy(node->info,key);
    node->st = node->dr = NULL;
    return node;
}

arbore* inserare(arbore* r, char key[100])
{
    if (r == NULL) return newarb(key);
    if (strcmp(key,r->info)<0) r->st = inserare(r->st, key);
    else r->dr = inserare(r->dr, key);
    return r;
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

int main()
{
    int n,m,niv=0,ok=0;
    cin>>n;
    r=NULL;
    for(int i=1; i<=n; i++)
    {
        char s[100];
        cin>>s;
        r=inserare(r,s);
    }
    SRD(r,niv);
    return 0;
}
