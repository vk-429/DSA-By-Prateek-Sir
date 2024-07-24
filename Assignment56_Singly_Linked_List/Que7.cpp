#include"SLL_ADT.cpp"

int main()
{
    int size;
    cout<<"Enter the Size of the List : ";
    cin>>size;
    list l1;
    cout<<"Enter Elements :-\n";
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        l1.push_back(x);
    }
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    node* t = l1.start;
    for(int i=0;i<size-n;i++)
        t = t->next;
    if(n>size)
        cout<<"Node does not exist!\n";
    else
        cout<<"Value at Node = "<<t->value<<"\n";
    return 0;
}