#include<iostream>
using namespace std;
int k;

void csort(int A[],int B[],int n)
{
    int C[k];
    for(int i=0; i<k+1; i++) C[i]=0;
    for(int j=1; j<=n; j++) C[A[j]]++;
    for(int i=1; i<=k; i++) C[i]+=C[i-1];
    for(int j=n; j>=1; j--)
    {
        B[C[A[j]]]=A[j];
        C[A[j]]=C[A[j]]-1;
    }
}

int main()
{
    int n;
    cin>>n;
    int A[n],B[n];
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
        if(A[i]>k) k=A[i];
    }
    csort(A,B,n);
    for(int i=1; i<=n; i++) cout<<B[i]<<" ";
    return 0;
}
