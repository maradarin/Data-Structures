#include <iostream>
#include <fstream>
using namespace std;

int nr, a[100], k, n;
void insert(int k) {
    nr++;
    int i=nr-1;
    a[i]=k;
    while(i!=0 && a[(i-1)/2]>a[i]) {
        int aux=a[i];
        a[i]=a[(i-1)/2]; a[(i-1)/2]=aux;
        i=(i-1)/2;
    }
}

int pop() {
    if(nr==1) {
        nr--;
        return a[0];
    }
    int r=a[0],i=0;
    a[0]=a[nr-1];
    nr--;
    while(i<=nr) {
        int l=2*i+1, r=2*i+2, mini=i;
        if(l<nr && a[l]<a[i]) mini=l;
        if(r<nr && a[r]<a[mini]) mini=r;
        if(mini!=i) {
            int aux=a[i];
            a[i]=a[mini]; a[mini]=aux;
            i=mini;
        }
        else break;
    }
    return r;
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++) {cin>>k; insert(k);}
    for(int i=0; i<nr; i++) cout<<a[i]<<" ";
    cout<<endl<<"Minimul este: "<<pop()<<endl;
    for(int i=0; i<nr; i++) cout<<a[i]<<" ";
    return 0;
}
