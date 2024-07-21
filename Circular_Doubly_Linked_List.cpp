#include<iostream>
using namespace std;


struct node
{
    node *prev;
    int value;
    node *next;
    node():prev(nullptr),value(0),next(nullptr){}
};

class cdll
{
    private:
        node *start;
    public:
        cdll():start(nullptr){}
        void push_back(int);
        void print();
        void push_front(int);
        void insert_after(int,int);
        void pop_front();
        void pop_back();
        void delete_after(int);
        node* search(int);
};

node* cdll::search(int val)
{
    node *t = start;
    if(start == nullptr)
        return start;
    do
    {
        if(t -> value == val)
            return t;
        t = t -> next;
    }while(t != start);
    return nullptr;
}

void cdll::delete_after(int n)
{
    if(n >= 0)
    {
        if(start == nullptr)
            cout<<"Underflow!\n";
        else
        {
            node *t = start;
            if(n == 0)
                pop_front();
            else
            {
                while(t -> next != start && n)
                {
                    t = t -> next;
                    n--;
                }
                if(n == 0)
                {
                    if(t -> next == start)
                    {
                        pop_back();
                        return;
                    }
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

void cdll::pop_back()
{
    if(start == nullptr)
        cout<<"Underflow!\n";
    else
    {
        node *t = start -> prev;
        if(start -> next == start)
            start = nullptr;
        else
        {
            start -> prev -> prev -> next = start;
            start -> prev = start -> prev -> prev;
        }
        delete t;
    }
}

void cdll::pop_front()
{
    if(start == nullptr)
        cout<<"Underflow!\n";
    else
    {
        node *t = start;
        if(start -> next != start)
        {
            start -> next -> prev = start -> prev;
            start -> prev -> next = start -> next;
            start = start -> next;
        }
        else
            start = nullptr;
        delete t;
    }
}

void cdll::insert_after(int n,int val)
{
    node *temp = new node();
    temp -> value = val;
    if(n >= 0)
    {
        if(n == 0)
            push_front(val);
        else
        {
            if(start == nullptr)
            {
                cout<<"Position Doesn't Exist!\n";
                return;
            }
            node *t = start;
            n--;
            while(t->next != start && n)
            {
                t = t -> next;
                n--;
            }
            if(n == 0)
            {
                temp -> next = t -> next;
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

void cdll::push_front(int val)
{
    node *temp = new node();
    temp -> value = val;
    if(start == nullptr)
    {
        start = temp;
        temp -> next = temp;
        temp -> prev = temp;
    }
    else
    {
        start -> prev -> next = temp;
        temp -> prev = start -> prev;
        temp -> next = start;
        start -> prev = temp;
        start = temp;
    }
}

void cdll::print()
{
    node *t = start;
    while(t)
    {
        cout<<t->value<<" <=> ";
        t = t -> next;
    }
    cout<<"\n";
}

void cdll::push_back(int val)
{
    node *temp = new node();
    temp -> value = val;
    if(start == nullptr)
    {
        start = temp;
        temp -> next = temp;
        temp -> prev = temp;
    }
    else
    {
        start -> prev -> next = temp;
        temp -> prev = start -> prev;
        start -> prev = temp;
        temp -> next = start;
    }
}
int main()
{
    cdll dl;
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