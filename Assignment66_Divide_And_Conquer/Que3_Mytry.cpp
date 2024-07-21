#include<iostream>
using namespace std;


int find_unique(int *arr,int start,int end)
{
    if(start == end)
        return arr[start];
    int mid = (end + start)/2;
    if(mid-1>=0 && mid+2<=end)
    {
        if(arr[mid] == arr[mid-1])
        {
            if(arr[mid+1] != arr[mid+2])
                return arr[mid+1];
            if((end - mid -2)>2)
                return find_unique(arr,mid+3,end);
        }
        else
        {
            if(arr[mid+1]==arr[mid+2])
                return arr[mid];
            if((mid - start)>2)
                return find_unique(arr,start,mid-1);
        }
    }
    if(arr[start] == arr[start+1])
        return arr[end];
    else
        return arr[start];
}

int main()
{
    int arr[] = { 1,1,2,4,4,5,5,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = find_unique(arr,0,n-1);
    cout<<ans<<"\n";
    return 0;
}