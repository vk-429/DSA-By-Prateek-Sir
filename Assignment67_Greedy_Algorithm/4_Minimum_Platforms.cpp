#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class time
{
    public:
        int hr;
        int min;
        time():hr(0),min(0){}
        time(int h,int m):hr(h),min(m){}
        bool operator>(time& t)
        {
            if(hr>t.hr)
                return true;
            if(hr == t.hr)
            {
                if(min > t.min)
                    return true;
                return false;
            }
            return false;
        }
        bool operator==(time& t)
        {
            return (hr == t.hr && min == t.min);
        }
        bool operator<(time& t)
        {
            if(hr < t.hr)
                return true;
            if(hr == t.hr)
            {
                if(min < t.min)
                    return true;
                return false;
            }
            return false;
        }
        bool operator>=(time& t)
        {
            return (*this>t || *this == t);
        }
        bool operator<=(time& t)
        {
            return (*this<t || *this == t);
        }
        friend ostream& operator<<(ostream&,time);
};

ostream& operator<<(ostream& mycout, time t)
{
    mycout<<t.hr<<" : "<<t.min<<"\n";
    return mycout;
}

class comparebydeparture
{
    public: 
        bool operator()(time& t1,time& t2)
        {
            return t1>t2;
        }
};

bool comparebyarrivaltime(pair<time,time>& p1, pair<time,time>& p2)
{
    return p1.first < p2.first;
}

int main()
{
    int n;
    cout<<"Enter no. of Trains : ";
    cin>>n;
    if(n<=0)
    {
        cout<<"Minimum No. of Platform Required = 0\n";
        return 0;
    }
    vector<time> arrival,departure;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival time of train "<<(i+1)<<" : ";
        int hr,min;
        cin>>hr>>min;
        arrival.push_back(time(hr,min));
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Departure time of train "<<(i+1)<<" : ";
        int hr,min;
        cin>>hr>>min;
        departure.push_back(time(hr,min));
    }
    vector<pair<time,time>> timings;
    for(int i=0;i<n;i++)
        timings.push_back(make_pair(arrival[i],departure[i]));
    sort(timings.begin(),timings.end(),comparebyarrivaltime);
    priority_queue<time,vector<time>,comparebydeparture> pq;
    int count = 1;
    for(int i=0;i<n;i++)
    {
        if(!pq.empty())
        {
            time t1 = pq.top();
            time t2 = timings[i].first;
            if(t1 > t2 && pq.size()==count)
                count++;
            else
            {
                while (!pq.empty() && t1<=t2)
                {
                    pq.pop();
                    if(!pq.empty())
                        t1 = pq.top();
                }
            }
        } 
        pq.push(timings[i].second);
    }
    cout<<"Minimum No. of Platform Required = "<<count<<"\n";
    return 0;
}