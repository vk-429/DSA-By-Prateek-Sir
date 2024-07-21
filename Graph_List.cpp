#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node():next(nullptr),data(0){}
    node(int v):data(v),next(nullptr){}
};


class Graph_List
{
    private:
        int v_count;
        int e_count;
        node **root;
    public:
        Graph_List(int size)
        {
            v_count=size;
            root = new node*[v_count];
            for(int i=0;i<v_count;i++)
                root[i]=nullptr;
        }
        void createGraph();
        void printGraph();
};

void Graph_List::createGraph()
{
    bool isdirected=false;
    cout<<"Enter 1 if graph is Directed else Enter 0 : ";
    cin>>isdirected;
    cout<<"Enter No. of Edges : ";
    cin>>e_count;
    cout<<"Enter Edges :-\n";
    int x,y;
    for(int i=1;i<=e_count;i++)
    {
        cout<<"Enter Nodes that are connected by edge "<<i<<" : ";
        cin>>x>>y;
        if(x<=v_count && y<=v_count)
        {
            node* t1 = new node(y);
            t1->next = root[x-1];
            root[x-1] = t1;
            if(!isdirected)
            {
                node* t2 = new node(x);
                t2->next = root[y-1];
                root[y-1] = t2;
            }
        }
        else
        {
            cout<<"Invalid Edge!\n";
            i--;
        }
    }
}

void Graph_List::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        node *t=root[i];
        cout<<"["<<(i+1)<<"] -> ";
        while(t != nullptr)
        {
            cout<<t->data<<" -> ";
            t = t->next;
        }
        cout<<"\n";
    }
}

int main()
{
    Graph_List g(5);
    g.createGraph();
    g.printGraph();
    return 0;
}

