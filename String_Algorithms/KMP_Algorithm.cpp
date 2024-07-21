#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix_table(string& pattern)
{
    int size = pattern.length();
    vector<int> ans(size);
    int i=1,j=0;
    ans[0]=0;
    while(i<size)
    {
        if(pattern[i]==pattern[j])
        {
            ans[i] = j+1;
            i++;j++;
        }
        else if(j>0)
            j = ans[j-1];
        else
        {
            ans[i] = 0;
            i++;
        }
    }
    return ans;
}

int KMPSearch(string pat, string txt)
{
    int i=0, j=0;
    vector<int> F = prefix_table(pat);
    int m = pat.length();
    int n = txt.length();
    while(i<=(n-m))
    {
        if(txt[i] == pat[j])
        {
            i++;j++;
            if(j==m)
                return (i-j);
        }
        else if(j>0)
            j = F[j-1];
        else
            i++;
    }
    return -1;
}

int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    int index;
    index = KMPSearch(pat, txt);
    if(index != -1)
        cout<<"Pattern Found at Index "<<index<<"\n";
    else
        cout<<"Pattern Not Found!\n";
    return 0;
} 

