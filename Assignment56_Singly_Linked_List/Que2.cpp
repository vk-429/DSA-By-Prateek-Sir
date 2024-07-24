#include"SLL_ADT.cpp"

list removeDuplicates(list& l1)
{
    if(l1.start == nullptr) return l1;
    node *prev,*curr;
    prev = l1.start;
    curr = prev->next;
    while(curr != nullptr)
    {
        if(prev->value == curr->value)
        {
            node* temp;
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return l1;
}

int main()
{
    cout<<"Enter Size : ";
    int n;
    cin>>n;
    cout<<"Enter Elements : ";
    list l1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l1.push_back(x);
    }
    list ans = removeDuplicates(l1);
    ans.print();
    return 0;
}
