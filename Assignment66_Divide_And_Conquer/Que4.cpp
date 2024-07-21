#include<iostream>
#include<climits>
#include<math.h>
using namespace std;
using lli = long long int;

lli sum_square(lli n)
{
    return (n*(n+1)*(2*n+1)/6);
}

int find_max(int p)
{
    lli low = 1;
    lli high = INT_MAX;
    lli ans = 0;
    while(low<=high)
    {
        lli mid = (low+high)/2;
        lli value = sum_square(mid);

        if(value <= p)
        {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    lli p = 14999;
    lli ans = find_max(p);
    cout<<ans<<"\n";
    return 0;
}