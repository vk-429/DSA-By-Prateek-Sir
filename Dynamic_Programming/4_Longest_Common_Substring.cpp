#include<iostream>
#include<vector>
using namespace std;

int LCS(string& a,string& b,int n,int m,vector<vector<int>>& dp)
{
    // if(n == 0 || m == 0)
    //     return 0;
    // if(dp[n][m] != -1)
    //     return dp[n][m];
    // if(a[n-1] == b[m-1])
    //     return (dp[n][m] = (1+LCS(a,b,n-1,m-1,dp)));
    // else
    //     return (dp[n][m] = max(LCS(a,b,n-1,m,dp),LCS(a,b,n,m-1,dp))); 
    // return dp[n][m];
    int max_length = 0;
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > max_length)
                    max_length = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return max_length;
}

int main()
{
    string a = "abcdef";
    string b = "abecdeg";
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    cout<<"Length of Logest Common Substring = "<<LCS(a,b,n,m,dp)<<"\n";
    return 0;
}