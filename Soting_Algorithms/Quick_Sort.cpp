#include<iostream>
using namespace std;

void quick_sort(int a[],int start, int end)
{
    if(start >= end)
        return;
    int pivot = a[start];
    int i = start+1;
    int j = end;
    int temp;
    while(i<j)
    {
        while(i<j && a[i]<pivot) i++;
        while(i<j && a[j]>=pivot) j--;
        
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;j--;
        }
    }
    if(a[i] < pivot)
    {
        a[start] = a[i];
        a[i] = pivot;
        quick_sort(a,start,i-1);
        quick_sort(a,i+1,end);
    }
    else 
    {
        if(i-1 != start)
        {
            a[start] = a[i-1];
            a[i-1] = pivot; 
        }
        quick_sort(a,start,i-2);
        quick_sort(a,i,end);
    }
}

int main()
{
    int a[] = {7,3,15,187,34,23,67,9};
    int n=sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}