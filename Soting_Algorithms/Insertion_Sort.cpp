#include<iostream>
using namespace std;

int main()
{
    int a[] = {23,4,1,22,10,5,11,19};
    int n=sizeof(a)/sizeof(a[0]);
    int temp,pivot;
    for(int i=1;i<n;i++)
    {
        pivot = a[i];
        int j=i-1;
        while(j>=0 && a[j]>pivot)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = pivot;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}