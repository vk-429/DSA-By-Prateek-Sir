#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>& s1)
{
    if(s1.size()<=1)
        return;
    stack<int> s2,s3;
    while(!s1.empty())
    {
        
        int maxi = s1.top();
        s1.pop();
        while(!s1.empty())
        {
            if(maxi<s1.top())
            {
                s3.push(maxi);
                maxi = s1.top();
            }
            else
                s3.push(s1.top());
            s1.pop();
        }
        s2.push(maxi);
        s1.swap(s3);
    }
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int main()
{
    int n;
    cout<<"Enter Size of the Stack : ";
    cin>>n;
    cout<<"Enter elements : ";
    int i;
    stack<int> st;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    sort(st);
    cout<<"Output :-\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    return 0;
}