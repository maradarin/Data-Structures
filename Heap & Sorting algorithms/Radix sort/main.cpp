#include<iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxi) maxi = arr[i];
    return maxi;
}

void countSort(int arr[], int n, int exp)
{
    int rez[n], cif[10] = {0};
    for (int i = 0; i < n; i++)
        cif[ (arr[i]/exp)%10 ]++;
    for (int i = 1; i < 10; i++)
        cif[i] += cif[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        rez[cif[ (arr[i]/exp)%10 ] - 1] = arr[i];
        cif[ (arr[i]/exp)%10 ]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = rez[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void afis(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[]={142, 234, 120, 130, 435, 2134, 8723, 643, 77, 11}, n = 10;
    radixsort(arr, n);
    afis(arr, n);
    return 0;
}
