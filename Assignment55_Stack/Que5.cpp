#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s;
    cout<<"Enter String : ";
    getline(cin,s);
    int n = s.length();
    stack<char> s1;
    for(int i=0;i<n;i++)
        s1.push(s[i]);
    for(int i=0;i<n;i++)
    {
        s[i] = s1.top();
        s1.pop();
    }
    cout<<s<<"\n";
    return 0;
}