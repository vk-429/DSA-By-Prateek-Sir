#include<iostream>
using namespace std;


struct node
{
    node *prev;
    int value;
    node *next;
    node():prev(nullptr),value(0),next(nullptr){}
};

class dll
{
    private:
        node *start;
    public:
        dll():start(nullptr){}
        void push_back(int);
        void print();
        void push_front(int);
        void insert_after(int,int);
        void pop_front();
        void pop_back();
        void delete_after(int);
        node* search(int);
};

node* dll::search(int val)
{
    node *t = start;
    while(t != nullptr)
    {
        if(t -> value == val)
            break;
        t = t -> next;
    }
    return t;
}

void dll::delete_after(int n)
{
    if(n >= 0)
    {
        if(start == nullptr)
            cout<<"Underflow!\n";
        else
        {
            node *t = start;
            if(n == 0)
            {
                if(t -> next != nullptr)
                    t -> next -> prev = nullptr;
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
                while(t -> next && n)
                {
                    t = t -> next;
                    n--;
                }
                if(n == 0)
                {
                    if(t -> next != nullptr)
                        t -> next -> prev = t -> prev;
                    t -> prev -> next = t -> next;
                    delete t;
                }
                else
                    cout<<"Position Doesn't Exist!\n";
            }
        }
    }
    else
        cout<<"Invalid Position!\n";
}

void dll::pop_back()
{
    if(start == nullptr)
        cout<<"Underflow!\n";
    else
    {
        node *t = start;
        while(t -> next != nullptr)
            t = t -> next;
        if(t -> prev != nullptr)
            t -> prev -> next = nullptr;
        else
            start = nullptr;
        delete t;
    }
}

void dll::pop_front()
{
    if(start == nullptr)
        cout<<"Underflow!\n";
    else
    {
        node *t = start;
        if(start -> next != nullptr)
            start -> next -> prev = nullptr;
        start = start -> next;
        delete t;
    }
}

void dll::insert_after(int n,int val)
{
    node *temp = new node();
    temp -> value = val;
    if(n >= 0)
    {
        if(n == 0)
        {
            temp -> next = start;
            if(start != nullptr)
                start -> prev = temp;
            start = temp;
        }
        else
        {
            if(start == nullptr)
            {
                cout<<"Position Doesn't Exist!\n";
                return;
            }
            node *t = start;
            n--;
            while(t->next && n)
            {
                t = t -> next;
                n--;
            }
            if(n == 0)
            {
                temp -> next = t -> next;
                if(t -> next != nullptr)
                    t -> next -> prev = temp;
                temp -> prev = t;
                t -> next = temp;
            }
            else
                cout<<"Position Doesn't Exist!\n";
        }
    }
    else
        cout<<"Invalid Position!\n";
}

void dll::push_front(int val)
{
    node *temp = new node();
    temp -> value = val;
    if(start == nullptr)
        start = temp;
    else
    {
        temp -> next = start;
        start -> prev = temp;
        start = temp;
    }
}

void dll::print()
{
    node *t = start;
    if(start == nullptr)
    {
        cout<<"List is Empty\n";
        return;
    }
    do
    {
        cout << t -> value << " -> ";
        t = t -> next;
    }while(t != start);
    cout<<"\n";
}

void dll::push_back(int val)
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
        t -> next = temp;
        temp -> prev = t;
    }
}
int main()
{
    dll dl;
    dl.push_back(5);
    dl.push_back(10);
    dl.push_back(15);
    dl.push_back(20);
    dl.push_front(2);
    dl.push_front(1);
    // dl.insert_after(0,30);
    // dl.insert_after(1,40);
    // dl.insert_after(8,100);
    // dl.insert_after(9,110);
    // dl.insert_after(4,80);
    dl.delete_after(4);
    dl.print();
    return 0;
}