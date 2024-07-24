#include"SLL_ADT.cpp"

int main()
{
    cout<<"Enter Size : ";
    int n;
    cin>>n;
    cout<<"Enter Elements :-\n";
    list l1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l1.push_front(x);
    }
    int x;
    cout<<"Enter X : ";
    cin>>x;
    if(l1.search(x) == nullptr)
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}