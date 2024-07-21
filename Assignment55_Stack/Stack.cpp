#include<iostream>
using namespace std;

class Stack
{
    private:
        int *p;
        int top;
        int capcacity;
    public:
        Stack(int cap):capcacity(cap)
        {
            top=-1;
            p=new int[capcacity];
        }
        int Top();
        void push(int);
        void pop();
        bool isEmpty();
        bool isFull();
        int size();
};

int Stack::size()
{
    return top+1;
}

bool Stack::isFull()
{
    return top==(capcacity-1);
}

bool Stack::isEmpty()
{
    return (top==-1);
}

void Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow\n";
        return;
    }
    top--;
}

void Stack::push(int value)
{
    if(isFull())
    {
        cout<<"Stack Overflow\n";
        return;
    }
    top++;
    p[top]=value;
}

int Stack::Top()
{
    if(!isEmpty())
        return p[top];
    cout<<"Stack Underflow\n";
    return -1;
}

// int main()
// {
//     int choice;
//     Stack s(20);
//     int value;
//     while(true)
//     {
//         cout<<"\n1. Push\n";
//         cout<<"2. Pop\n";
//         cout<<"3. Get Top\n";
//         cout<<"4. Get Size\n";
//         cout<<"5. Exit\n\n";
//         cout<<"Enter your choice : ";
//         cin>>choice;
//         switch (choice)
//         {
//         case 1:
//             cout<<"Enter value : ";
//             cin>>value;
//             s.push(value);
//             break;
//         case 2:
//             s.pop();
//             break;
//         case 3:
//             cout<<"Top = "<<s.Top()<<"\n";
//             break;
//         case 4:
//             cout<<"Size = "<<s.size()<<"\n";
//             break;
//         case 5:
//             exit(0);
//         default:
//             cout<<"Invalid Choice!\n";
//             break;
//         }
//     }
//     return 0;
// }