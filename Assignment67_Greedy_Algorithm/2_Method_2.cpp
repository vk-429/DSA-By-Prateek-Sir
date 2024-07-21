#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

bool comparebyendtime(pair<int,int>& p1,pair<int,int>& p2)
{
    return p1.second<p2.second;
}

int main()
{
    vector<pair<int,int>> timings;
    int n;
    cout<<"Enter No. of Activities : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Starting and Ending Time of Activity "<<(i+1)<<" : ";
        int start,end;
        cin>>start>>end;
        timings.push_back(make_pair(start,end));
    }
    sort(timings.begin(),timings.end(),comparebyendtime);
    int ans=0;
    if(n == 0)
    {
        cout<<ans<<"\n";
        return 0;
    }
    else
        ans++;
    int i = 0, j = 1;
    while(j<n)
    {
        if(timings[i].second <= timings[j].first)
        {
            i = j;
            j++;
            ans++;
        }
        else
            j++;
    }
    cout<<"Maximum Number of Programs that can be watched = "<<ans<<"\n";
    return 0;
}