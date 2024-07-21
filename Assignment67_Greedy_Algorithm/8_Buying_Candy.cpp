#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"Enter No. of Candies : ";
    cin>>n;
    vector<int> price(n);
    cout<<"Enter Price of Each Candy :-\n";
    for(int i=0;i<n;i++)cin>>price[i];
    int k;
    cout<<"Enter value of K : ";
    cin>>k;
    sort(price.begin(),price.end());
    int i=0,j=n-1;
    int min_price = 0;
    while(j >= i)
    {
        min_price += price[i];
        i++;
        j -= k;
    }
    int max_price = 0;
    i = n-1,j=0;
    while(j <= i)
    {
        max_price += price[i];
        i--;
        j += k;
    }
    cout<<"Minimum Price = "<<min_price<<"\n";
    cout<<"Maximum Price = "<<max_price<<"\n";
    return 0;
}