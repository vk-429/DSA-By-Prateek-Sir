#include<iostream>
using namespace std;

class Graph_Matrix
{
    private:
        int **adj;
        int v,e;
        int *predecessor;
        int *pathlength;
        bool *status;
    public:
        Graph_Matrix(int size)
        {
            v = size;
            adj = new int*[v];
            for(int i=0;i<v;i++)
                adj[i] = new int[v]{0};
            predecessor = new int[v];
            pathlength = new int[v];
            status = new bool[v];
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
            delete[] predecessor;
            delete[] pathlength;
            delete[] status;
        }
        void dijsktra(int);
        int find_current();
        void find_path(int,int);
};

void Graph_Matrix::find_path(int source,int destination)
{
    if(source == destination)
    {
        cout<<"Already At the Destination\n";
        return;
    }
    if(source>=v || destination>=v || source<0 || destination<0)
    {
        cout<<"Invalid Source or Destination!\n";
        return;
    }
    dijsktra(source);
    if(pathlength[destination] == INT_MAX)
    {
        cout<<"There is No Path Between Entered Locations\n";
        return;
    }
    int path[v];
    int i=0,distance=0;
    path[0] = destination;
    while(source != destination)
    {
        path[++i] = predecessor[destination];
        distance += adj[path[i]][destination];
        destination = path[i];
    }
    cout<<"Sortest Path : ";
    for(int j=i;i>=0;i--)
    {
        cout<<path[i];
        if(i!=0) cout<<" => ";
    }
    cout<<"\n";
    cout<<"Shortest Distance = "<<distance<<"\n";
}
int Graph_Matrix::find_current()
{
    int min = INT_MAX;
    int index = 0;
    for(int i=0;i<v;i++)
    {
        if(status[i]==false && pathlength[i]<min)
        {
            min = pathlength[i];
            index = i;
        }
    }
    if(min == INT_MAX)
        return -1;
    return index;
}

void Graph_Matrix::dijsktra(int source)
{
    int i;
    for(i=0;i<v;i++)
    {
        pathlength[i] = INT_MAX;
        predecessor[i] = -1;
        status[i] = false;
    }
    pathlength[source] = 0;
    status[source] = true;
    int current = source;
    while(current != -1)
    {
        status[current] = true;
        for(i=0;i<v;i++)
        {
            if(adj[current][i] != 0 )
            {
                if(status[i] == false && (pathlength[current]+adj[current][i])<pathlength[i])
                {
                    pathlength[i] = pathlength[current]+adj[current][i];
                    predecessor[i] = current;
                }
            }
        }
        current = find_current();
    }

}

void Graph_Matrix::createGraph()
{
    bool isdirected=false;
    cout<<"Enter 1 if graph is Directed else Enter 0 : ";
    cin>>isdirected;
    cout<<"Enter No. of Edges : ";
    cin>>e;
    cout<<"Enter Edges :-\n";
    int x,y,wt;
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter Nodes that are connected by edge "<<i<<" : ";
        cin>>x>>y;
        cout<<"Enter Weight : ";
        cin>>wt;
        if(x<=v && y<=v && x>=0 && y>=0)
        {
            adj[x][y]=wt;
            if(!isdirected)
                adj[x][y]=wt;
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
    //g.print();
    //g.dijsktra(0);
    g.find_path(1,3);
    return 0;
}