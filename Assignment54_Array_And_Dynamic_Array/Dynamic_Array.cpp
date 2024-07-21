#include<iostream>
using namespace std;

class DynamicArray
{
    private:
        int *array;
        int lastindex;
        int capacity;
    public:
        DynamicArray()
        {
            capacity=1;
            lastindex=-1;
            array = new int[capacity];
        }
        ~DynamicArray()
        {
            delete[] array;
            lastindex=-1;
            capacity=0;
        }
        void append(int value)
        {
            if(lastindex==capacity-1)
                doublearray();
            lastindex++;
            array[lastindex]=value;
        }
        void insert(int index, int value)
        {
            if(lastindex == capacity-1)
            {
                doublearray();
            }
            if(index > lastindex+1)
            {
                cout<<"Invalid Index!\n";
                return;
            }
            for(int i=lastindex+1;i>index;i--)
                array[i]=array[i-1];
            array[index]=value;
            lastindex++;
        }
        int search(int value)
        {
            for(int i=0;i<=lastindex;i++)
            {
                if(array[i]==value)
                    return i;
            }
            return -1;
        }
        void edit(int index,int value)
        {
            if(index>=0 && index<=lastindex)
                array[index]=value;
            else
                cout<<"Invalid Index!\n";
        }
        void Delete(int index)
        {
            if(index>=0 && index<=lastindex)
            {
                for(int i=index;i<lastindex;i++)
                    array[i]=array[i+1];
                lastindex--;
                if(capacity>=2 && (lastindex+1)==capacity/2)
                    halfarray();
            }
            else
                cout<<"Invalid Index!\n";
        }
        void doublearray()
        {
            capacity=2*capacity;
            int *temp = new int[capacity];
            for(int i=0;i<=lastindex;i++)
                temp[i]=array[i];
            delete[] array;
            array=temp;
        }
        void halfarray()
        {
            if(capacity>=2)
            {
                capacity=capacity/2;
                int *temp = new int[capacity];
                for(int i=0;i<=lastindex;i++)
                    temp[i]=array[i];
                delete[] array;
                array=temp;
            }
        }
        void shrink_to_fit()
        {
            capacity=lastindex+1;
            int *temp = new int[capacity];
            for(int i=0;i<=lastindex;i++)
                temp[i]=array[i];
            delete[] array;
            array=temp;
        }
        void reverse()
        {
            for(int i=0;i<(lastindex+1)/2;i++)
            {
                array[i]=array[i]+array[lastindex-i];
                array[lastindex-i]=array[i]-array[lastindex-i];
                array[i]=array[i]-array[lastindex-i];
            }
        }
        void sort()
        {
            for(int i=0;i<lastindex;i++)
            {
                for(int j=i+1;j<=lastindex;j++)
                {
                    if(array[i]>array[j])
                    {
                        array[i]=array[i]+array[j];
                        array[j]=array[i]-array[j];
                        array[i]=array[i]-array[j];
                    }
                }
            }
        }
        int Size()
        {
            return lastindex+1;
        }
        int Capacity()
        {
            return capacity;
        }
        void printArray()
        {
            for(int i=0;i<=lastindex;i++)
                cout<<array[i]<<" ";
            cout<<"\n";
        }
};


int main()
{
    DynamicArray a;
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.insert(0,10);
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.insert(1,20);
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.insert(2,40);
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.append(30);
    a.append(50);
    a.printArray();
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.insert(2,70);
    a.printArray();
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.shrink_to_fit();
    cout<<"Size = "<<a.Size()<<" Capacity = "<<a.Capacity()<<"\n";
    a.reverse();
    a.printArray();
    a.sort();
    a.printArray();
    return 0;
}