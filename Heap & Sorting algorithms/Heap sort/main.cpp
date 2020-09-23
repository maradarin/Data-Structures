#include <iostream>
#include <fstream>
using namespace std;
int a[100],k,nr,n;

void insert(int k)
{
    nr++;
    int i=nr-1;
    a[i]=k;
    while(i!=0 && a[(i-1)/2]>a[i])
    {
        int aux=a[i];
        a[i]=a[(i-1)/2];
        a[(i-1)/2]=aux;
        i=(i-1)/2;
    }
}

void heapify(int i, int nr)
{
    while(i<=nr)
    {
        int l=2*i+1, r=2*i+2, maxi=i;
        if(l<nr && a[l]>a[maxi]) maxi=l;
        if(r<nr && a[r]>a[maxi]) maxi=r;
        if(maxi!=i)
        {
            int aux=a[i];
            a[i]=a[maxi];
            a[maxi]=aux;
            i=maxi;
        }
        else break;
    }
}

void heapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(i,nr);

    for (int i=n-1; i>=0; i--)
    {
        int aux=a[0];
        a[0]=a[i];
        a[i]=aux;
        heapify(0,i);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) {cin>>k; insert(k);}
    heapSort(nr);
    for(int i=0;i<nr;i++) cout<<a[i]<<" ";
}
