#include<iostream>
#define EMPTY_HEAP -1
using namespace std;

class HEAP
{
    private:
        int capacity;
        int lastindex;
        int *arr;
    public:
        HEAP():capacity(1),lastindex(-1){arr = new int[capacity];}
        HEAP(int cap):capacity(cap),lastindex(-1){arr = new int[capacity];}
        void insert(int);
        int del();
        bool isEmpty(){return lastindex==-1;}
        bool isFull(){return lastindex==(capacity-1);}
        void doubleArray();
        void halfArray();
        void edit(int,int);
        int max();
        int size(){return lastindex+1;}
        int find(int);
        int get(int);
        ~HEAP(){delete[] arr;}
};

int HEAP::get(int index)
{
    if(index >=0 && index <= lastindex)
        return arr[index];
    cout<<"Either HEAP is Empty or Index Doesn't Exist!\n";
    return -1;
}

int HEAP::find(int ele)
{
    for(int i = 0; i <= lastindex; i++)
        if(arr[i] == ele) return i;
    return -1;
}

int HEAP::max()
{
    if(lastindex != -1)
        return arr[lastindex];
    return EMPTY_HEAP;
}

void HEAP::edit(int index, int v)
{
    if(index >= 0 && index <= lastindex)
        arr[index] = v;
    else
        cout<<"Index Doesn't Exist!\n";
}

void HEAP::halfArray()
{
    capacity = capacity / 2;
    int *temp = new int[capacity];
    for(int i = 0; i < lastindex; i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}

void HEAP::doubleArray()
{
    capacity = 2 * capacity;
    int *temp = new int[capacity];
    for(int i = 0; i < lastindex; i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}

int HEAP::del()
{
    if(isEmpty())
        return EMPTY_HEAP;
    int index = 0;
    int leftindex = 1, rightindex = 2;
    int gonna_delete = arr[0];
    int last = arr[lastindex];
    while(rightindex <= lastindex)
    {
        if(arr[leftindex] > arr[rightindex])
        {
            if(last > arr[leftindex])
                break;
            arr[index] = arr[leftindex];
            index = leftindex;
        }
        else
        {
            if(last > arr[rightindex])
                break;
            arr[index] = arr[rightindex];
            index = rightindex;
        }
        leftindex = 2*index + 1;
        rightindex = 2*index + 2;
    }
    arr[index] = last;
    lastindex--;
    if(capacity>1 & lastindex<(capacity/2))
        halfArray();
    return gonna_delete;
}

void HEAP::insert(int v)
{
    if(isFull())
        doubleArray();
    int index;
    int parentindex=0;

    for(index = lastindex + 1; index > 0; index = parentindex)
    {
        parentindex = (index - 1) / 2;
        if(arr[parentindex] < v)
            arr[index] = arr[parentindex];
        else
            break;
    }
    arr[index] = v;
    lastindex++;
}

void heap_sort(int A[],int N)
{
    HEAP obj(N);
    for(int i=0;i<N;i++)
        obj.insert(A[i]);
    for(int i=N-1;i>=0;i--)
        A[i]=obj.del();
}

int main()
{
    int A[]={21,24,10,14,23,25,8,11,49,3};
    heap_sort(A,10);
    cout<<endl;
    for(int i=0;i<=9;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}