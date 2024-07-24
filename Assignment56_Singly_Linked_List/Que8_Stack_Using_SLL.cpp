#include<iostream>
using namespace std;

struct node
{
    node *next;
    int value;
    node():next(nullptr),value(0){}
    node(int val):next(nullptr),value(val){}
};

class Stack_SLL
{
    private:
        node *top;
    public:
        Stack_SLL():top(nullptr){}
        void push(int);
        void pop();
        int Top();
        bool isEmpty();
};

bool Stack_SLL::isEmpty()
{
    return (top == nullptr);
}

int Stack_SLL::Top()
{
    if(top == nullptr)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
    return top->value;
}

void Stack_SLL::pop()
{
    if(top == nullptr)
        cout<<"Stack Underflow!\n";
    else
    {
        node *t = top;
        top = top->next;
        delete t;
    }
}

void Stack_SLL::push(int data)
{
    node *t = new node(data);
    t -> next = top;
    top = t;
}
