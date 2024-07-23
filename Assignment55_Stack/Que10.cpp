#include<iostream>
using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int capacity;
        int *arr;
    public:
        Queue(int cap)
        {
            front = -1;
            rear = -1;
            capacity = cap;
            arr = new int[capacity];
        }
        void enqueue(int);
        int dequeue();
        int top();
        int size();
        bool isFull();
        bool isEmpty();
        ~Queue(){delete[] arr;}
};

bool Queue::isEmpty()
{
    return (rear == -1);
}

bool Queue::isFull()
{
    return ((front == rear +1) || ((rear - front + 1) == capacity));
}

int Queue::size()
{
    if(front == -1)
        return 0;
    if(rear >= front)
        return (rear - front + 1);
    return ((capacity - front) + (rear + 1));
}

int Queue::top()
{
    if(front == -1)
    {
        cout<<"Queue is Empty!\n";
        return -1;
    }
    return arr[front];
}

int Queue::dequeue()
{
    if(rear == -1)
        return -1;
    int temp = arr[front];
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
    return temp;
}

void Queue::enqueue(int v)
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
    Queue q(20);
    q.enqueue(2);
    // q.enqueue(3);
    cout<<q.dequeue()<<" ";
    // q.enqueue(4);
    cout<<q.dequeue()<<" ";
    cout<<"\n";
    return 0;
}