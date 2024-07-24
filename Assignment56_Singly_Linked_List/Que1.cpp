#include<iostream>
using namespace std;

struct node
{
    int value;
    node* next;
    node():value(0),next(nullptr){}
    node(int val):value(val),next(nullptr){}
};

class sll
{
    private:
        node* head;
    public:
        sll():head(nullptr){}
        void insert(int);
        bool search(int);
};

void sll::insert(int data)
{
    node* temp = new node(data);
    if(head)
        temp -> next = head;
    head = temp;
}

bool sll::search(int key)
{
    node *t = head;
    while(t)
    {
        if(t->value == key)
            return true;
        t = t->next;
    }
    return false;
}

int main()
{
    cout<<"Enter Size : ";
    int n;
    cin>>n;
    cout<<"Enter Elements :-\n";
    sll l1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l1.insert(x);
    }
    int x;
    cout<<"Enter X : ";
    cin>>x;
    int result = l1.search(x);
    if(result == true)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}