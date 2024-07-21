#include<iostream>
using namespace std;

void merge(int a[], int s1, int e1, int s2, int e2)
{
    int size = e2-s1+1;
    int temp[size];
    int k=0,i=s1,j=s2;
    while(i<=e1 && j<=e2)
    {
        if(a[i]<a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i<=e1)
    {
        temp[k] = a[i];
        i++;k++;
    }
    while(j<=e2)
    {
        temp[k] = a[j];
        j++;k++;
    }
    for(int i=s1,k=0;i<=e2,k<size;i++,k++)
        a[i] = temp[k];
}

void merge_sort(int a[], int i, int j)
{
    int mid = (i+j)/2;

    if(i<j)
    {
        merge_sort(a,i,mid);
        merge_sort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}

int main()
{
    int a[] = {23,4,1,22,10,5,11,19};
    int n=sizeof(a)/sizeof(a[0]);
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}