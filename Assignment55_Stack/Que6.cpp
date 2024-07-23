#include<iostream>
#include<stack>
using namespace std;

void print_bracket_numbers(string& s)
{
    stack<char> s1;
    string braces;
    int size=s.length();
    int pop_count=0, push_count=1;
    for(int i=0;i<size;i++)
    {
        if(s[i]=='(')
        {
            if(s1.empty())
                pop_count = push_count-1;
            s1.push('(');
            cout<<push_count<<" ";
            push_count++;
        }
        else if(s[i]==')')
        {
            cout<<pop_count+s1.size()<<" ";
            s1.pop();
        }
    }
    cout<<"\n";
}

int main()
{
    string s;
    cout<<"Enter Input String : ";
    cin>>s;
    print_bracket_numbers(s);
    return 0;
}