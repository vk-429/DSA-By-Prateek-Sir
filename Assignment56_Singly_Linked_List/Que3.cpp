#include"SLL_ADT.cpp"

list& swapPairwise(list& l)
{
    if(l.start == nullptr || l.start->next == nullptr)
        return l;
    node *prev,*curr;
    prev = l.start;
    curr = l.start->next;
    do
    {
        prev->value = prev->value+curr->value;
        curr->value = prev->value - curr->value;
        prev->value = prev->value - curr->value;
        prev = curr->next;
        if(prev)
            curr = prev->next;
    } while (prev && curr);
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
    l1 = swapPairwise(l1);
    cout<<"After Swapping :-\n";
    l1.print();
    return 0;
}