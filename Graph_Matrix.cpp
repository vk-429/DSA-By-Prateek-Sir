#include<iostream>
using namespace std;

class Graph_Matrix
{
    private:
        int **adj;
        int v,e;
    public:
        Graph_Matrix(int size)
        {
            v = size;
            adj = new int*[v];
            for(int i=0;i<v;i++)
                adj[i] = new int[v]{0};
        }
        void createGraph();
        void print()
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                    cout<<adj[i][j]<<" ";
                cout<<"\n";
            }

        }
        ~Graph_Matrix()
        {
            for(int i=0;i<v;i++)
                delete[] adj[i];
            delete[] adj;
        }
};

void Graph_Matrix::createGraph()
{
    bool isdirected=false;
    cout<<"Enter 1 if graph is Directed else Enter 0 : ";
    cin>>isdirected;
    cout<<"Enter No. of Edges : ";
    cin>>e;
    cout<<"Enter Edges :-\n";
    int x,y;
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter Nodes that are connected by edge "<<i<<" : ";
        cin>>x>>y;
        if(x<=v && y<=v)
        {
            adj[x-1][y-1]=1;
            if(!isdirected)
                adj[x-1][y-1]=1;
        }
        else
        {
            cout<<"Invalid Edge!\n";
            i--;
        }
    }
}

int main()
{
    Graph_Matrix g(5);
    g.createGraph();
    g.print();
    return 0;
}