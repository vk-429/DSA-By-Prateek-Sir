#include"SLL_ADT.cpp"
#include<unordered_set>

bool isLoop(list& l)
{ 
    unordered_set<node*> visited;
    node *t = l.start;
    while(t)
    {
        if(visited.find(t) != visited.end())
            return true;
        visited.emplace(t);
        t = t->next;
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the Size of the List : ";
    cin>>n;
    list l1;
    cout<<"Enter Elements :-\n";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l1.push_back(x);
    }
    bool result = isLoop(l1);
    if(result == true)
        cout<<"Yes, it contains\n";
    else
        cout<<"No loop\n";
    return 0;
}