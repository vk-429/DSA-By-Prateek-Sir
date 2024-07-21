#include<iostream>
using namespace std;

class Graph_Matrix
{
    private:
        int **adj;
        int v,e;
        int *predecessor;
        int *length;
        bool *status;
        bool isdirected = false;
    public:
        Graph_Matrix()
        {
            v=0;
            e=0;
            adj=nullptr;
            predecessor=nullptr;
            length=nullptr;
            status=nullptr;
        }
        void create_matrix();
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
            delete[] length;
            delete[] status;
        }
        void make_tree(int,Graph_Matrix&);
        int find_current();
        void print_edge();
};

void Graph_Matrix::print_edge()
{
    cout<<"\nEdges to be included in the Spanning Tree :-\n";
    int wt_tree=0;
    for(int i=0;i<v;i++)
    {
        for(int j=i+1;j<v;j++)
        {
            if(adj[i][j] != 0)
            {
                cout<<i;
                if(isdirected)
                    cout<<" -> ";
                else cout<<" <-> ";
                cout<<j<<"\n";
                wt_tree += adj[i][j];
            }
        }
    }
    cout<<"Weight of the Spanning Tree = "<<wt_tree<<"\n";
}


int Graph_Matrix::find_current()
{
    int min = INT_MAX;
    int index = 0;
    for(int i=0;i<v;i++)
    {
        if(status[i]==false && length[i]<min)
        {
            min = length[i];
            index = i;
        }
    }
    if(min == INT_MAX)
        return -1;
    return index;
}

void Graph_Matrix::make_tree(int source, Graph_Matrix& span_tree)
{
    span_tree.v = v;
    span_tree.create_matrix();
    span_tree.e = v-1;
    span_tree.isdirected = isdirected;
    int i;
    for(i=0;i<v;i++)
    {
       length[i] = INT_MAX;
        predecessor[i] = -1;
        status[i] = false;
    }
    length[source] = 0;
    status[source] = true;
    int current = source;
    int count = 0;
    while(current != -1)
    {
        status[current] = true;
        if(current != source)
        {
            count++;
            span_tree.adj[current][predecessor[current]] = adj[current][predecessor[current]];
            span_tree.adj[predecessor[current]][current] = adj[predecessor[current]][current];
        }
        for(i=0;i<v;i++)
        {
            if(adj[current][i] != 0 )
            {
                if(status[i] == false && adj[current][i] < length[i])
                {
                    length[i] = adj[current][i];
                    predecessor[i] = current;
                }
            }
        }
        current = find_current();
        if(count < v-1  && current == -1 )
        {
            cout<<"No Spanning Tree Possible\n";
            exit(0);
        }
    }

}

void Graph_Matrix::create_matrix()
{
    adj = new int*[v];
    for(int i=0;i<v;i++)
        adj[i] = new int[v]{0};
    predecessor = new int[v];
    length = new int[v];
    status = new bool[v];
}

void Graph_Matrix::createGraph()
{
    cout<<"Enter 1 if graph is Directed else Enter 0 : ";
    cin>>isdirected;
    cout<<"Enter No. of Nodes : ";
    cin>>v;
    create_matrix();
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
                adj[y][x]=wt;
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
    Graph_Matrix g;
    g.createGraph();
    Graph_Matrix span_tree;
    int source=0;
    cout<<"Enter Source Node : ";
    cin>>source;
    g.make_tree(source,span_tree);
    span_tree.print_edge();
    return 0;
}