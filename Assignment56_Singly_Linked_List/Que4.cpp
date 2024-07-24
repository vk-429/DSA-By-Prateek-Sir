#include"SLL_ADT.cpp"

list& moveLasttoFront(list& l)
{
    if(l.start == nullptr || l.start->next == nullptr)
        return l;
    node *prev = nullptr;
    node* temp = l.start;
    while(temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    temp -> next = l.start;
    prev -> next = nullptr;
    l.start = temp;
    return l;
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
    l1 = moveLasttoFront(l1);
    cout<<"After moving last node to the front :-\n";
    l1.print();
    return 0;
}