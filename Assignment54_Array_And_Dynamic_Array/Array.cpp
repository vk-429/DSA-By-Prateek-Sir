#include<iostream>
using namespace std;

class Array
{
    private:
        int *a;
        int capacity;
        int lastindex;
    public:
        Array(int cap)
        {
            capacity=cap;
            lastindex=-1;
            a=new int[capacity];
        }
        void append(int value)
        {
            if(lastindex<capacity-1)
            {
                lastindex++;
                a[lastindex]=value;
            }
            else
                cout<<"Array is Already Full!\n";
        }
        void insert(int index, int value)
        {
            if(lastindex<capacity-1)
            {
                for(int i=index;i<=lastindex;i++)
                    a[i+1]=a[i];
                a[index]=value;
                lastindex++;
            }
            else
                cout<<"Array is Already Full!\n";
        }
        int get(int index)
        {
            if(index>=0 && index<=lastindex)
                return a[index];
            else
                cout<<"Invalid Index!\n";
        }

        int Size()
        {
            return lastindex+1;
        }

        int search(int value)
        {
            for(int i=0;i<=lastindex;i++)
            {
                if(a[i]==value)
                    return i;
            }
            return -1;
        }

        void Delete(int index)
        {
            for(int i=index;i<lastindex;i++)
                a[i]=a[i+1];
            lastindex--;
        }
        void reverse()
        {
            for(int i=0;i<(lastindex+1)/2;i++)
            {
                a[i]=a[i]+a[lastindex-i];
                a[lastindex-i]=a[i]-a[lastindex-i];
                a[i]=a[i]-a[lastindex-i];
            }
        }
        void sort()
        {
            for(int i=0;i<lastindex;i++)
            {
                for(int j=i+1;j<=lastindex;j++)
                {
                    if(a[i]>a[j])
                    {
                        a[i]=a[i]+a[j];
                        a[j]=a[i]-a[j];
                        a[i]=a[i]-a[j];
                    }
                }
            }
        }
        void printArray()
        {
            for(int i=0;i<=lastindex;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
};

int main()
{
    cout<<"Enter Size of the Array : ";
    int n;
    cin>>n;
    cout<<"Enter Array Elements : ";
    Array a(10);
    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        a.append(x);
    }
    a.printArray();
    cout<<"\n";
    cout<<"Enter Element You Want to Search : ";
    int value;
    cin>>value;
    int index = a.search(value);
    if(index!=-1)
        cout<<"Element found at "<<index<<"\n";
    else
        cout<<"Element Not Found!\n";

    cout<<"Enter the Index to Delete : ";
    cin>>index;
    a.Delete(index);
    a.printArray();
    a.reverse();
    a.printArray();
    a.sort();
    a.printArray();
    return 0;
}