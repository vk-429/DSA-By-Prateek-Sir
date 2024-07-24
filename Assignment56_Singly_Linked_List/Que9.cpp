#include"SLL_ADT.cpp"
#include<stack>

int main()
{
    list l1;
    cout<<"Enter Elements of Linked List(-1 to quit) : ";
    while(true)
    {
        int x;
        cin>>x;
        if(x==-1)
            break;
        l1.push_back(x);
    }
    node *t = l1.start;
    stack<int> s1;
    while(t)
    {
        s1.push(t->value);
        t = t->next;
    }
    t = l1.start;
    while(t->value == s1.top())
    {
        t = t->next;
        s1.pop();
        if(t == nullptr)
            break;
    }
    if(s1.empty())
        cout<<"Yes, Given Linked List is a Polyndrome\n";
    else
        cout<<"Given Linked List is not a Polyndrome\n";
    return 0;
}