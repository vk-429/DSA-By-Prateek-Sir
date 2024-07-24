#include"SLL_ADT.cpp"

bool isLoop(list& l)
{ 
    node *t1 = nullptr,*t2 = nullptr;
    t1 = l.start;
    if(t1)
        t2 = t1->next;
    while(t1 && t2)
    {
        t1 = t1->next;
        if(t2 -> next)
            t2 = t2->next->next;
        else
            t2 = nullptr;
        if(t1 == t2)
            return true;
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