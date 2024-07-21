#include<iostream>
#include<ctime>
using namespace std;

int getRandom(int l,int r)
{
    srand(time(nullptr));
    return (l + (rand()%(r-l+1)));
}

int randomizedBinerySearch(int *arr,int l,int r,int target)
{
    if(r>=l)
    {
        int randommid = getRandom(l,r);
        if(arr[randommid] == target)
            return randommid;
        if(target > arr[randommid])
            return randomizedBinerySearch(arr, randommid+1,r,target);
        else
            return randomizedBinerySearch(arr, l,randommid-1,target);
    }
    return -1;
}

int main()
{
    int arr[] = {2,4,9,12,18,21,30,41};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = randomizedBinerySearch(arr, 0,n-1,12);
    
    if(result == -1)
        cout<<"Value not found.\n";
    else
        cout<<"Value found at index : "<<result<<"\n";
    return 0;
}