#include"Stack.cpp"

int main()
{
    int n;
    cout<<"Enter Stack Size(>0) : ";
    cin>>n;
    Stack s1(n);
    cout<<"Enter elements :-\n";
    int i;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s1.push(x);
    }
    Stack temp(n/2);
    i=0;
    while(i<(n/2))
    {
        temp.push(s1.Top());
        s1.pop();
        i++;
    }
    s1.pop();
    while(!temp.isEmpty())
    {
        s1.push(temp.Top());
        temp.pop();
    }
    cout<<"Modified Stack :-\n";
    while(!s1.isEmpty())
    {
        cout<<s1.Top()<<" ";
        s1.pop();
    }
    cout<<"\n";
    return 0;
}