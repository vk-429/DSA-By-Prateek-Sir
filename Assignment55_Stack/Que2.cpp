#include<iostream>
#include<stack>
using namespace std;

bool isCorrect(string& s)
{
    stack<char> s1;
    int size=s.length();
    if(size==0)
        return false;
    for(int i=0;i<size;i++)
    {
        if(s1.empty())
        {
            s1.push(s[i]);
            i++;
        }
        if(((s1.top()=='[') && (s[i]==']'))||((s1.top()=='{') && (s[i]=='}'))||((s1.top()=='(') && (s[i]==')')))
            s1.pop();
        else 
            s1.push(s[i]);
    }
    if(s1.empty())
        return true;
    
    return false;
}

int main()
{
    string s;
    cout<<"Enter Input String : ";
    cin>>s;
    bool result;
    result=isCorrect(s);
    if(result==true)
        cout<<"Expression is Correct\n";
    else
        cout<<"Expression is inCorrect\n";
    return 0;
}