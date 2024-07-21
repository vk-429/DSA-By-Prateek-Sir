#include<iostream>
#include<queue>
using namespace std;

struct node
{
    node *left;
    int value;
    node *right;
    node():left(nullptr),right(nullptr),value(0){}
    node(int v):left(nullptr),right(nullptr),value(v){}
    void preorder()
    {
        if(this != nullptr)
        {
            cout<<value<<" ";
            left->preorder();
            right->preorder();
        }
    }
    void postorder()
    {
        if(this != nullptr)
        {
            left->postorder();
            right->postorder();
            cout<<value<<" ";
        }
    }
    void inorder()
    {
        if(this != nullptr)
        {
            left->inorder();
            cout<<value<<" ";
            right->inorder();
        }
    }
    void levelorder()
    {
        queue<node*> q;
        if(this != nullptr)
            q.emplace(this);
        while(!q.empty())
        {
            node *root = q.front();
            cout<<root->value<<" ";
            q.pop();
            if(root -> left != nullptr)
                q.emplace(root -> left);
            if(root -> right != nullptr)
                q.emplace(root -> right);
        }
    }

    int height()
    {
        queue<node*> q;
        if(this != nullptr)
            q.emplace(nullptr);
        node *root = this;
        int count = 0;
        while(!q.empty())
        {
            if(root -> left != nullptr)
                q.emplace(root -> left);
            if(root -> right != nullptr)
                q.emplace(root -> right);
            if(q.front() != nullptr)
                q.pop();
            root = q.front();
            if(root == nullptr)
            {
                q.pop();
                count++;
                q.emplace(nullptr);
                root = q.front();
                if(root == nullptr)
                    break;
            }
        }
        return count;
    }

    int height_rec()
    {
        if(this == nullptr)
            return 0;
        return max(left->height_rec(),right->height_rec())+1;
    }
};

void printCurrentLevel(node *root, int level)
{
    if(root == nullptr)
        return;
    if(level == 0)
        cout<<root->value<<" ";
    else if(level>0)
    {
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void levelorderrec(node *root)
{
    int h = root->height_rec();
    for(int i = 0; i < h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    node * root = new node(2);
    root -> left = new node(4);
    root -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);
    root -> right -> right ->left = new node(8);
    root -> right -> right -> right = new node(9);
    root -> right -> right ->left -> left = new node(10);
    root -> right -> right ->left -> right = new node(11);
    root -> right -> right ->left -> right -> left = new node(12);
    root->postorder();
    cout<<"\n";
    root->preorder();
    cout<<"\n";
    root->inorder();
    cout<<"\n";
    root->levelorder();
    cout<<"\nHeight = "<<root->height()<<"\n";
    cout<<"\nHeight = "<<root->height_rec()<<"\n";
    levelorderrec(root);
    return 0;
}