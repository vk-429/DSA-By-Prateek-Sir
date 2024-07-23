#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s;
    cout<<"Enter String : ";
    cin>>s;
    int n = s.length();
    stack<char> st;
    for(int i=n-1;i>=0;i--)
        st.push(tolower(s[i]));
    char curr = st.top();
    st.pop();
    int count = 1;
    string ans;
    while(!st.empty())
    {
        if(curr == st.top())
            count++;
        else
        {
            ans += count+'0';
            ans += curr;
            count = 1;
            curr = st.top();
        }
        st.pop();
    }
    ans += count+'0';
    ans += curr;
    cout<<ans<<"\n";
    return 0;
}