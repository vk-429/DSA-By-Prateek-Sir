#include<iostream>
using namespace std;

struct node
{
    node *left;
    int value;
    node *right;
    node():left(nullptr),right(nullptr),value(0){}
    node(int v)
    {
        left = nullptr;
        value = v;
        right = nullptr;
    }
};

int main()
{
    node *root = new node(10);
    root -> left = new node(15);
    root -> right = new node(20);
    root -> left -> right = new node(30);
    root -> right -> left = new node(40);

    // If you have told to make any function related to tree
    // then besides creating a whole tree data structure just 
    // create this temporary tree to check your functions working
    return 0;
}