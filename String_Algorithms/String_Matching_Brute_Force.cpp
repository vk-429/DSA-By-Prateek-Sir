#include<iostream>
#include<string>
using namespace std;

int main()
{
    char t[] = "ABCAADABC";
    char p[] = "AADC";
    int n=9;
    int m=4;
    int flag = 0;
    for(int i=0;i<=(n-m);i++)
    {
        int j=0;
        while(j<m && t[i+j]==p[j])
            j++;
        if(j==m)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        cout<<"Pattern Found\n";
    else 
        cout<<"Pattern Not Found\n";
    return  0;
}