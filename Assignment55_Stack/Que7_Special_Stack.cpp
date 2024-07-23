#include<iostream>
#include<stack>
using namespace std;

class Special_Stack
{
    private:
        int capacity;
        int top;
        int *arr;
        stack<int> min_stack;
    public:
        Special_Stack()
        {
            capacity = 1;
            top = -1;
            arr = new int[capacity];
        }
        Special_Stack(int cap)
        {
            capacity = cap;
            top = -1;
            arr = new int[capacity];
        }
        void double_array();
        void half_array();
        void push(int);
        void pop();
        bool isEmpty(){return top==-1;}
        int getMin(){return min_stack.top();}
};

void Special_Stack::pop()
{
    min_stack.pop();
    top--;
    if(top>1 && top<capacity/2)
        half_array();
}

void Special_Stack::push(int data)
{
    if(min_stack.empty())
        min_stack.push(data);
    else
        min_stack.push(min(min_stack.top(),data));
    if(top == capacity-1)
        double_array();
    top++;
    arr[top] = data;
}

void Special_Stack::half_array()
{
    capacity/=2;
    int *temp = new int[capacity];
    for(int i=0;i<=top;i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}

void Special_Stack::double_array()
{
    capacity *= 2;
    int *temp = new int[capacity];
    for(int i=0;i<=top;i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}

int main()
{
    Special_Stack s1;
    int n;
    cout<<"Enter the Size of Stack : ";
    cin>>n;
    cout<<"Enter Elements :-\n";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s1.push(x);
    }
    cout<<"Minimum Element = "<<s1.getMin()<<"\n";
    return 0;
}


