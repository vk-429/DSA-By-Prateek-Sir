#include"SLL_ADT.cpp"

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
    int key;
    cout<<"Enter Key : ";
    cin>>key;
    int count=0;
    node* t = l1.start;
    while(t)
    {
        if(t->value == key)
            count++;
        t = t->next;
    }
    cout<<"No. of Occurence of the Key = "<<count<<"\n";
    return 0;
}