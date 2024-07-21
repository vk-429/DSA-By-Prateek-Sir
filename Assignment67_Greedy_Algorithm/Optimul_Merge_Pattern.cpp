#include<iostream>
#include<set>
#include<queue>
using namespace std;

int main()
{
    cout<<"Enter No. of files : ";
    int n;
    cin>>n;
    //multiset<int> c_time;
    priority_queue<int,vector<int>,greater<int>> pq;
    cout<<"Enter Computation Time :-\n";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }
    int min_cost = 0;
    while(pq.size()>1)
    {
        int i = pq.top();
        pq.pop();
        int j = pq.top();
        pq.pop();
        pq.push(i+j);
        min_cost += (i+j);
    }
    cout<<"Minimum Cost Needed = "<<min_cost<<"\n";
    return 0;
}

// Also we can use priority Queue insteed of multiset
