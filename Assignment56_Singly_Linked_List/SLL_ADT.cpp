#include<iostream>
using namespace std;


struct node
{ 
    int value;
    node *next;
    node(){value=0;next=nullptr;}
    node(int val){value = val, next = nullptr;}
};

class list
{
    public:
        node *start;
        list():start(nullptr){}
        void push_back(int );
        void push_front(int);
        void print();
        void insert_specific(int,int);
        void pop_back();
        void pop_front();
        void delete_specific(int);
        list& operator=(list &);
        node* search(int);
};

list& list::operator=(list& l)
{
    if(this == &l) return *this;
    while(start)
    {
        node* temp = start;
        start = start -> next;
        delete temp;
    }
    node *t = l.start;
    while(t)
    {
        push_back(t->value);
        t = t -> next;
    }
    return *this;
}

node* list::search(int val)
{
    node *t = start;
    if(start == nullptr)
        return nullptr;
    while(t->next != nullptr)
    {
        if(t->value == val)
            return t;
        t = t -> next;
    }
    if(t->value == val)
        return t;
    return nullptr;
}

void list::delete_specific(int n)
{
    node *t = start;
    if(start == nullptr)
    {
        cout<<"Underflow!\n";
        return;
    }
    if(n == 1)
    {
        start = start -> next;
        delete t;
    }
    else
    {
        if(t -> next == nullptr)
        {
            cout<<"Position Doesn't Exist!\n";
            return;
        }
        n-=2;
        while(t -> next -> next && n)
            t = t -> next;
        if(n == 0)
        {
            t -> next = t -> next -> next;
            delete t -> next;
        }
        else
            cout<<"Position Doesn't Exist!\n";
    }

}

void list::pop_front()
{
    node *t = start;
    if(start == nullptr)
        cout<<"Underflow!\n";
    else
    {
        start = start -> next;
        delete t;
    }
}

void list::pop_back()
{
    node *t = start;
    if(start == nullptr)
        cout<<"Underflow!\n";
    else
    {
        if(start -> next == nullptr)
        {
            start = nullptr;
            delete t;
        }
        else
        {
            while(t->next->next)
                t = t -> next;
            delete t -> next;
            t -> next = nullptr;
        }
    }
}

void list::insert_specific(int n,int val)
{
    node *temp = new node();
    temp -> value = val;
    if(start == nullptr)
        start = temp;
    else
    {
        if(n == 1)
        {
            temp -> next = start;
            start = temp;
        }
        else
        {
            node *t = start;
            n-=2;
            while(t->next && n)
            {
                t = t -> next;
                n--;
            }
            if(n == 0)
            {
                temp -> next = t -> next;
                t -> next = temp;
            }
            else
                cout<<"Position Doesn't Exist!\n";
        }
    }
}

void list::print()
{
    node *t = start;
    while(t != nullptr)
    {
        cout << t -> value <<" -> ";
        t = t -> next;
    }
    cout<<"\n";
}

void list::push_front(int val)
{
    node *temp = new node();
    temp -> value = val;
    temp -> next = start;
    start = temp;
}

void list::push_back(int val)
{
    node *temp = new node();
    temp -> value = val;
    if(start == nullptr)
        start = temp;
    else
    {
        node *t = start;
        while(t -> next != nullptr)
            t = t -> next;
        t->next = temp;
    }
}
