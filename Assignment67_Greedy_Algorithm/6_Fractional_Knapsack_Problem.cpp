#include<iostream>
#include<vector>
#include<tuple>
#include<utility>
#include<algorithm>
using namespace std;

bool comparebyvpkg(const pair<double,double>& t1, const pair<double,double>& t2)
{
    double p1 = t1.first/t1.second;
    double p2 = t2.first/t2.second;
    return p1>p2;
}

int main()
{
    cout<<"Enter No. of Items : ";
    int n;
    cin>>n;
    vector<pair<double,double>> items;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter value and weight of item "<<(i+1)<<" : ";
        double v,w;
        cin>>v>>w;
        items.push_back(make_pair(v,w));
    }
    
    double capacity;
    cout<<"Enter Capacity of Bori : ";
    cin>>capacity;
    sort(items.begin(),items.end(),comparebyvpkg);
    int i = 0;
    double maxvalue=0;
    while(i<n && capacity>0)
    {
        if(items[i].second <= capacity)
        {
            maxvalue += items[i].first;
            capacity -= items[i].second;
        }
        else
        {
            maxvalue += ((items[i].first/items[i].second)*capacity);
            capacity = 0;
        }
        i++;
    }
    cout<<"Maximum Total Value of Knapsack = "<<maxvalue<<"\n";
    return 0;
}