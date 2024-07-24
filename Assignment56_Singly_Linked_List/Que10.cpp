#include"SLL_ADT.cpp"

int find_middle_element(list& l)
{
    if(l.start == nullptr)
    {
        cout<<"List is Empty!\n";
        return -1;
    }
    node *t1,*t2;
    t1 = t2 = l.start;
    while(t2->next)
    {
        t1 = t1->next;
        t2 = t2->next->next;
        if(t2 == nullptr)
            break;
    }
    return t1->value;
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
    int middle = find_middle_element(l1);
    cout<<"Middle Element = "<<middle<<"\n";
    return 0;
}