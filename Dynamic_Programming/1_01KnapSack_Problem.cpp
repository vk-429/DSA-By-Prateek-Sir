#include<iostream>
using namespace std;



int knapSack(int W,int *wt,int *val,int n,int** dp)
{
    if(n==0 || W==0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];
    if(wt[n-1]<=W)
        return dp[n][W] = max((val[n-1]+knapSack(W-wt[n-1],wt,val,n-1,dp)),(knapSack(W,wt,val,n-1,dp)));
    return dp[n][W] = knapSack(W,wt,val,n-1,dp);
}


int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    int** dp = new int*[n+1];
    for (int i = 0; i <= n; ++i) 
        dp[i] = new int[W+1];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= W; ++j)
            dp[i][j] = -1;
    cout<<"Max Value of KnapSack = "<<knapSack(W,wt,val,n,dp)<<"\n";
    return 0;
}