#include <iostream>
using namespace std;

int majorityElement(int A[], int n)
{
    int m, i = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == 0)
        {
            m = A[j];
            i = 1;
        }
        else
        {
            if(m == A[j]) i++;
            else i--;
        }
    }
    return m;
}

int main()
{
    int n;
    cin>>n;
    int v[n+1];
    for(int i=0; i<n; i++) cin>>v[i];
    int rez=majorityElement(v,n), cont=0;
    for(int i=0; i<n; i++)
        if(v[i]==rez) cont++;
    if(cont>n/2) cout<<"Elementul majoritar exista, este: "<<rez;
    else cout<<"Elementul majoritar nu exista";
    return 0;
}
