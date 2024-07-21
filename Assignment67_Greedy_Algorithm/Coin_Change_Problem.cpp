#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> denominations = {5,2,1,1000,2000,500,100,20,50,10};
    int n = denominations.size();
    sort(denominations.begin(),denominations.end());
    int amount;
    cout<<"Enter Amount : ";
    cin>>amount;
    int i = n-1;
    while(amount<denominations[i]) i--;
    int j = i;
    while(amount>0)
    {
        while(amount>=denominations[j])
        {
            cout<<denominations[j]<<" ";
            amount -= denominations[j];
        }
        j--;
    }
    cout<<"\n";
    return 0;
}