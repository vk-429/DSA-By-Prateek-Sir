#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Stack Size(>0) : ";
    cin>>n;
    stack<int> s1;
    cout<<"Enter elements :-\n";
    int i;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s1.push(x);
    }
    stack<int> temp;
    i=0;
    while(i<(n/2))
    {
        temp.push(s1.top());
        s1.pop();
        i++;
    }
    s1.pop();
    while(!temp.empty())
    {
        s1.push(temp.top());
        temp.pop();
    }
    cout<<"Modified Stack :-\n";
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<"\n";
    return 0;
}