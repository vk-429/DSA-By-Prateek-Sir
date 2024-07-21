#include<iostream>
#include<queue>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
    node():left(nullptr),right(nullptr),data(0){}
    node(int v):left(nullptr),right(nullptr),data(v){}
};

class BST
{
    private:
        node *root;
    public:
        BST():root(nullptr){}
        node* insertrec(node*,int);
        void insert(int);
        node* delrec(node*,int);
        void Delete(int);
        void preorder();
        void inorder();
        void postorder();
        void postorderrec(node*);
        void inorderrec(node*);
        void preorderrec(node*);
        int heightrec(node*);
        int height();
        node* minelementrec(node*);
        node* maxelementrec(node*);
        node* minelement();
        node* maxelement();
        node* search(int);
        void levelorder();
        bool isEmpty();
};

bool BST::isEmpty()
{
    return root==nullptr;
}

node* BST::delrec(node* root,int value)
{
    if(root == nullptr)
        return root;
    else if(value > root->data)
        root->right = delrec(root->right, value);
    else if(value < root->data)
        root->left = delrec(root->left,value);
    else
    {
        if((root->left == nullptr) && (root->right ==nullptr))
        {
            delete root;
            return nullptr;
        }
        else if(root->right == nullptr)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == nullptr)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            node* temp = minelementrec(root->right);
            root->data = temp->data;
            root->right = delrec(root->right,temp->data);
        }
    }
    return root;
}

void BST::Delete(int value)
{
    root = delrec(root,value);
}

void BST:: levelorder()
{
    if(root == nullptr)
        return;
    queue<node*> q;
    q.emplace(root);
    while(!q.empty())
    {
        node *curr = q.front();
        cout << curr->data << " ";
        q.pop();
        if(curr->left != nullptr)
            q.emplace(curr->left);
        if(curr->right != nullptr)
            q.emplace(curr->right);
    }
}

node* BST::search(int value)
{
    if(root == nullptr)
        return root;
    node* t=root;
    while(t!=nullptr)
    {
        if(value>t->data)
            t = t -> right;
        else if(value<t->data)
            t = t -> left;
        else
            break;
    }
    return t;
}

node* BST::maxelementrec(node* root)
{
    if(root == nullptr || root->right == nullptr)
        return root;
    return maxelementrec(root->right);
}
node* BST::maxelement()
{
    return maxelementrec(root);
}

node* BST::minelementrec(node* root)
{
    if(root == nullptr || root->left == nullptr)
        return root;
    return minelementrec(root->left);
}
node* BST::minelement()
{
    return minelementrec(root);
}

int BST::heightrec(node* root)
{
    if(root == nullptr)
        return 0;
    return max(heightrec(root->left),heightrec(root->right))+1;
}

int BST::height()
{
    return heightrec(root);
}

void BST::postorderrec(node *ptr)
{
    if(ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<ptr->data<<" ";
    }
}
void BST::postorder()
{
    postorderrec(root);
}

void BST::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<ptr->data<<" ";
        inorderrec(ptr->right);
    }
}
void BST::inorder()
{
    inorderrec(root);
}

void BST::preorderrec(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->data<<" ";
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::preorder()
{
    preorderrec(root);
}

node* BST::insertrec(node* root, int value)
{
    if(root == nullptr)
        return new node(value);
    if(value > root -> data)
        root -> right = insertrec(root->right,value);
    else if(value < root -> data)
        root -> left = insertrec(root->left,value);
    else
        cout<<"Duplicates Not Allowed!\n";
    return root;
}

void BST::insert(int value)
{
    root = insertrec(root,value);
}

int main()
{
    BST T;
    cout << "Inserting elements: 50, 30, 70, 20, 40, 60, 80" << endl;
    T.insert(50);
    T.insert(30);
    T.insert(70);
    T.insert(20);
    T.insert(40);
    T.insert(60);
    T.insert(80);

    cout << "Inorder traversal: ";
    T.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    T.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    T.postorder();
    cout << endl;

    cout << "Level order traversal: ";
    T.levelorder();
    cout << endl;

    cout << "Height of tree: " << T.height() << endl;

    node *minNode = T.minelement();
    if (minNode != nullptr)
        cout << "Minimum element: " << minNode->data << endl;

    node *maxNode = T.maxelement();
    if (maxNode != nullptr)
        cout << "Maximum element: " << maxNode->data << endl;

    int searchValue = 90;
    node *searchNode = T.search(searchValue);
    if (searchNode != nullptr)
        cout << "Element " << searchValue << " found in the tree." << endl;
    else
        cout << "Element " << searchValue << " not found in the tree." << endl;

    cout << "Deleting element 20" << endl;
    T.Delete(20);
    cout << "Inorder traversal after deleting 20: ";
    T.inorder();
    cout << endl;

    cout << "Deleting element 30" << endl;
    T.Delete(30);
    cout << "Inorder traversal after deleting 30: ";
    T.inorder();
    cout << endl;

    cout << "Deleting element 50" << endl;
    T.Delete(50);
    cout << "Inorder traversal after deleting 50: ";
    T.inorder();
    cout << endl;

    return 0;
    return 0;
}