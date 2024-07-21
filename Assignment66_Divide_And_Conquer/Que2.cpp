#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& v,int left,int mid,int right)
{
    int temp[right-left+1];
    int s1 = left;
    int e1 = mid;
    int s2 = mid+1;
    int e2 = right;
    int i = s1, j = s2;
    int k = 0;
    int count = 0;
    while(i<=e1 && j<=e2)
    {
        if(v[i] <= v[j])
        {
            temp[k] = v[i];
            i++;k++;
        }
        else
        {
            temp[k] = v[j];
            j++;k++;
            count+=(mid-i+1);
        }
    }
    while(i<=e1)
    {
        temp[k] = v[i];
        i++;k++;
    }
    while(j<=e2)
    {
        temp[k] = v[j];
        j++;k++;
    }
    for(i=s1,k=0;i<=e2;i++,k++)
        v[i] = temp[k];
    return count;
}

int mergesort(vector<int>& v,int left,int right)
{
    int count = 0;
    if(right>left)
    {
        int mid = (left+right)/2;
        count += mergesort(v,left,mid);
        count += mergesort(v,mid+1,right);
        count += merge(v,left,mid,right);
    }
    return count;

}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    int i;
    for(i=0;i<n;i++)cin>>vec[i];
    int count = mergesort(vec,0,n-1);
    cout<<"Ans : "<<count<<"\n";
    return 0;
}