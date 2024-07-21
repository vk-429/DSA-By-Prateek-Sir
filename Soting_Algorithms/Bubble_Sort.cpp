#include<iostream>
using namespace std;

int main()
{
    int a[] = {2,8,3,5,9,8,12,11};
    int n=sizeof(a)/sizeof(a[0]);
    int flag;
    for(int i=n-1;i>=0;i--)
    {
        flag =0;
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                flag = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 0)
            break;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}