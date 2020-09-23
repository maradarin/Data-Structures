#include<iostream>
using namespace std;

long* Radix_2_ac_long(long *a, int n, long *temp)// Sorts in ascending order
{
    int b[256] = {0}, poz1, poz2, poz3, poz4;
    long *aux;

    poz1 = a[0] & 255;
    b[poz1] = 1;
    poz2 = ((a[0] >> 8) & 255) + 256;
    b[poz2] = 1;
    for(int i = 1 ; i < n ; i++)
    {
        b[a[i] & 255]++;
        b[((a[i] >> 8) & 255) + 256]++;
    }

    if(b[poz1] == n) return a;
    else
    {
        for(int i = 1 ; i < 256 ; i++) b[i] = b[i-1] + b[i];
        for(int i=0; i < n; i++) temp[b[a[i] & 255]++]=a[i];
        aux = a;
        a = temp;
        temp = aux;
    }
}


long temp[10],v[10];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>v[i];
    //long v[9]= {12, 24, 52, 5, 123, 64, 45, 8, 21};
    //long v[7]= {127, 324, 173, 4, 38, 217, 134};
    Radix_2_ac_long(v,n,temp);
    for(int i=1; i<=n; i++) cout<<temp[i]<<" ";
}
