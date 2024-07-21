#include<iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of Programs : ";
    cin>>n;
    map<int,int> timings;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Starting and Ending time for program "<<(i+1)<<" : ";
        int x,y;
        cin>>x>>y;
        timings.emplace(make_pair(y,x));
    }
    int ans = 0;
    map<int,int>::iterator it1,it2;
    if(!timings.empty())
    {
        ans++;
        it1 = timings.begin();
    }
    else
    {
        cout<<ans<<"\n";
        return 0;
    }
    it2 = (++timings.begin());
    while(it2!=timings.end())
    {
        if(it1->first < it2->second)
        {
            it1 = it2;
            it2++;
            ans++;
        }
        else
            it2++;
    }
    cout<<"Maximum Number of Programs that can be watched = "<<ans<<"\n";
    return 0;
}