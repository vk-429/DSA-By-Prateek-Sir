#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"["<<(i)<<"] -> ";
        for(auto&x:adj[i])
            cout<<x<<" -> ";
        cout<<"\n";
    }
}

void dfs(vector<int> adj[],int size,int source)
{
    bool visited[size]={0};
    stack<int> st;
    st.push(source);
    visited[source]=1;
    while(!st.empty())
    {
        int curr=st.top();
        cout<<curr<<" ";
        st.pop();
        for(int i=0;i<adj[curr].size();i++)
        {
            if(visited[adj[curr][i]]==0)
            {
                st.push(adj[curr][i]);
                visited[adj[curr][i]]=1;
            }
        }
    }
    cout<<"\n";
}

void bfs(vector<int> adj[],int size,int source)
{
    bool visited[size]={0};
    queue<int> q;
    q.push(source);
    visited[source]=1;
    while(!q.empty())
    {
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i=0;i<adj[curr].size();i++)
        {
            if(!visited[adj[curr][i]])
            {
                visited[adj[curr][i]]=1;
                q.push(adj[curr][i]);
            }
        }
    }
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    printGraph(adj,v);
    dfs(adj,v,1);
    bfs(adj,v,0);
    return 0;
}