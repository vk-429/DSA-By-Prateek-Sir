#include<iostream>
using namespace std;

class Deque
{
    private:
        int front;
        int rear;
        int capacity;
        int *arr;
    public:
        Deque(int cap)
        {
            front = -1;
            rear = -1;
            capacity = cap;
            arr = new int[capacity];
        }
        void push_back(int);
        void push_front(int);
        int get_rear();
        int get_front();
        void pop_front();
        void pop_back();
        int size();
        bool isEmpty();
        bool isFull();
        ~Deque(){delete[] arr;}
};

bool Deque::isFull()
{
    return (capacity == size());
}

bool Deque::isEmpty()
{
    return (rear == -1);
}

int Deque::size()
{
    if(front == -1)
        return 0;
    if(rear >= front)
        return (rear - front + 1);
    return ((capacity - front) + (rear + 1));
}

void Deque::pop_back()
{
    if(isEmpty())
    {
        cout<<"Underflow!\n";
        return;
    }
    if(rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        if(rear == 0)
            rear = capacity - 1;
        else
            rear--;
    }
}

void Deque::pop_front()
{
    if(isEmpty())
    {
        cout<<"Underflow!\n";
        return;
    }
    if(rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        if(front == capacity-1)
            front = 0;
        else
            front++;
    }
}

int Deque::get_front()
{
    return arr[front];
}

int Deque::get_rear()
{
    return arr[rear];
}

void Deque::push_front(int v)
{
    if(isFull())
    {
        cout<<"Queue is Already Full\n";
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
        front = capacity-1;
    else
        front--;
    arr[front] = v;
}

void Deque::push_back(int v)
{
    if(isFull())
    {
        cout<<"Queue is Already Full\n";
        return;
    }
    if(rear == (capacity-1))
        rear = -1;
    if(front == -1)
        front++;
    rear++;
    arr[rear] = v;
}

int main()
{
    Deque dq(5);
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    cout<<"Size = "<<dq.size()<<"\n";
    dq.pop_front();
    cout<<"Size = "<<dq.size()<<"\n";
    dq.pop_front();
    cout<<"Size = "<<dq.size()<<"\n";
    dq.push_back(6);
    dq.push_front(10);
    dq.pop_back();
    dq.pop_back();
    dq.push_front(11);
    dq.push_front(12);
    cout<<"Size = "<<dq.size()<<"\n";
    while(!dq.isEmpty())
    {
        cout<<dq.get_front()<<" ";
        dq.pop_front();
    }
    cout<<"\n";
    return 0;
}