#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec = {2,-3,0,10,12,5};
    int n = vec.size();
    sort(vec.begin(),vec.end());
    int maxi = 0;
    int mini = 0;
    for(int i=0;i<n/2;i++)
        maxi+=abs(vec[i]-vec[n-i-1]);
    for(int i=0;i<n-1;i+=2)
        mini+=abs(vec[i]-vec[i+1]);
    cout<<"Maximum Sum = "<<maxi<<"\n";
    cout<<"Minimum Sum = "<<mini<<"\n";
    return 0;
}
