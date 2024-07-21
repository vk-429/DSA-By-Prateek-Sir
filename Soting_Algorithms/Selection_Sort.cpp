#include<iostream>
using namespace std;

int main()
{
    int a[] = {23,4,1,22,10,5,11,19};
    int n=sizeof(a)/sizeof(a[0]);
    int min,t;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        if(min != i)
        {
            t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}