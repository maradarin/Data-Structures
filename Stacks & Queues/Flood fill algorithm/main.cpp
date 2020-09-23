#include <iostream>
using namespace std;

int A[100][100], di[4]= {0,0,-1,1}, dj[4]= {1,-1,0,0},m;

struct coada
{
    int i,j;
    coada *prev, *next;
}*start, *fin;

void pushr(int x, int y)
{
    coada *p = new coada();
    p->i=x;
    p->j=y;
    if (fin == NULL && start==NULL)
        start = fin = p;
    else
    {
        p->prev = fin;
        fin->next = p;
        fin = p;
    }
}

int popl(coada *&start, coada *&fin)
{
    coada *p = start;
    int result=p->i;
    start = start->next;
    if (start == NULL)
        fin = NULL;
    else
        start->prev = NULL;
    delete p;
    return result;
}


int lung(coada *p)
{
    int nr=0;
    while(p!=NULL)
    {
        nr++;
        p=p->next;
    }
    return nr;
}


void Fill(int istart ,int jstart ,int v)
{
    pushr(istart , jstart);
    A[istart][jstart] = v;
    while(lung(start)!=0)
    {
        int x = start->i, y = start->j;
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = x + di[k], jv = y + dj[k]; // di[4]= {0,0,-1,1} ; dj[4]= {1,-1,0,0}
            if(iv >= 1 && iv <= m && jv >= 1 && jv <= m && A[iv][jv] ==1)
            {
                A[iv][jv] = v;
                pushr(iv , jv);
            }
        }
        popl(start,fin);
    }
}


int main()
{
    int v=1;
    cin>>m;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=m; j++)
            cin>>A[i][j];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=m; j++)
            if(A[i][j]==1)
            {
                v++;
                Fill(i,j,v);
            }
    cout<<endl;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
