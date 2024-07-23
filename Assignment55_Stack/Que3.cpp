#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of Elements : ";
    cin>>n;
    vector<int> tree;
    cout<<"Enter Elements :-\n";
    int i;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        tree.push_back(x);
    }
    int start=0,end=0;
    int level = 0,count=0;
    i=0;
    while(count<n)
    {
        if(level%2==0)
        {
            for(i=min(end,n-1);i>=start;i--)
            {
                cout<<tree[i]<<" ";
                count++;
            }
        }
        else
        {
            for(i=start;i<=min(end,n-1);i++)
            {
                cout<<tree[i]<<" ";
                count++;
            }
        }
        start = end+1;
        level++;
        end+=pow(2,level);
    }
    cout<<"\n"; 
    return 0;
}