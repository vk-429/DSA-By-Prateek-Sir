#include<iostream>
using namespace std;

int knapSack(int rod_size,int *meter,int *price,int n,int **dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=rod_size;w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(w >= meter[i-1])
                dp[i][w] = max(price[i-1]+dp[i][w-meter[i-1]],dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][rod_size];
}

int main()
{
    int meter[] = {1,2,3,4,5,6,7};
    int price[] = {2,5,4,5,3,2,6};
    int rod_size = 10;
    int n = sizeof(price)/sizeof(price[0]);
    int** dp = new int*[n+1];
    for (int i = 0; i <= n; ++i) 
        dp[i] = new int[rod_size+1];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= rod_size; ++j)
            dp[i][j] = -1;
    cout<<"Maximum Profit of Shopkeeper = "<<knapSack(rod_size,meter,price,n,dp)<<"\n";
    return 0;
}