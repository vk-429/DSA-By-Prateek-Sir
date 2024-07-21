#include<iostream>
using namespace std;

int knapSack(int W,int *wt,int *val,int n,int **dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(w >= wt[i-1])
                dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
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