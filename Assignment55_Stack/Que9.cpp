#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter String 1 : ";
    cin>>s1;
    cout<<"Enter String 2 : ";
    cin>>s2;
    stack<char> st1,st2;
    int n = s1.length();
    int m = s2.length();
    for(int i=0;i<n;i++)
    {
        if(!st1.empty() && s1[i] == '#')
            st1.pop();
        else
            st1.push(s1[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(!st2.empty() && s2[i] == '#')
            st2.pop();
        else
            st2.push(s2[i]);
    }
    if(st1 == st2)
        cout<<"True\n";
    else
        cout<<"False\n";
    return 0;
}