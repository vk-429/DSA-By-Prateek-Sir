#include<iostream>
#include<queue>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
    int height;
    node():left(nullptr),right(nullptr),data(0),height(0){}
    node(int v):left(nullptr),right(nullptr),data(v),height(1){}
};

class AVL_Tree
{
    private:
        node *root;
    public:
        AVL_Tree():root(nullptr){}
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
        int height_node(node*);
        int height();
        int getbf(node*);
        node* minelementrec(node*);
        node* maxelementrec(node*);
        node* minelement();
        node* maxelement();
        node* search(int);
        void levelorder();
        bool isEmpty();
        node* left_rotation(node*);
        node* right_rotation(node*);
};

node* AVL_Tree::right_rotation(node* x)
{
    node* y = x->right;
    node* t = y->left;
    x->right = t;
    y->left = x;

    x->height = max(height_node(x->left),height_node(x->right))+1;
    y->height = max(height_node(y->left),height_node(y->right))+1;

    return y;
}

node* AVL_Tree::left_rotation(node* x)
{
    node* y = x->left;
    node* t = y->right;

    y->right = x;
    x->left = t;
    x->height = max(height_node(x->left),height_node(x->right))+1;
    y->height = max(height_node(y->left),height_node(y->right))+1;

    return y;
}

bool AVL_Tree::isEmpty()
{
    return root==nullptr;
}

node* AVL_Tree::delrec(node* root,int value)
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

    root -> height = max(height_node(root->left),height_node(root->right))+1;

    int balanceFactor = getbf(root);

    if(balanceFactor > 1)
    {
        if((getbf(root->left)>=0))
            return right_rotation(root);
        else
        {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }
    }

    if(balanceFactor < -1)
    {
        if((getbf(root->right)<=0))
            return left_rotation(root);
        else
        {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }
    }

    return root;
}

void AVL_Tree::Delete(int value)
{
    root = delrec(root,value);
}

node* AVL_Tree::insertrec(node* root, int value)
{
    if(root == nullptr)
        return new node(value);
    if(value > root -> data)
        root -> right = insertrec(root->right,value);
    else if(value < root -> data)
        root -> left = insertrec(root->left,value);
    else
        return root;
    
    root -> height = max(height_node(root->left),height_node(root->right))+1;

    int balanceFactor = getbf(root);

    if(balanceFactor > 1)
    {
        if(value < root->left->data)
            return right_rotation(root);
        else
        {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }
    }

    if(balanceFactor < -1)
    {
        if(value > root->right->data)
            return left_rotation(root);
        else
        {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }
    }

    return root;
}

void AVL_Tree::insert(int value)
{
    root = insertrec(root,value);
}

void AVL_Tree:: levelorder()
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

node* AVL_Tree::search(int value)
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

node* AVL_Tree::maxelementrec(node* root)
{
    if(root == nullptr || root->right == nullptr)
        return root;
    return maxelementrec(root->right);
}
node* AVL_Tree::maxelement()
{
    return maxelementrec(root);
}

node* AVL_Tree::minelementrec(node* root)
{
    if(root == nullptr || root->left == nullptr)
        return root;
    return minelementrec(root->left);
}
node* AVL_Tree::minelement()
{
    return minelementrec(root);
}

int AVL_Tree::getbf(node* ptr)
{
    if(ptr == nullptr) return 0;
    return height_node(ptr->right)-height_node(ptr->left);
}

int AVL_Tree::height_node(node* ptr)
{
    if(ptr == nullptr) return 0;
    return ptr->height;
}

int AVL_Tree::height()
{
    if(root==nullptr)
        return 0;
    return root->height;
}

void AVL_Tree::postorderrec(node *ptr)
{
    if(ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<ptr->data<<" ";
    }
}
void AVL_Tree::postorder()
{
    postorderrec(root);
}

void AVL_Tree::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<ptr->data<<" ";
        inorderrec(ptr->right);
    }
}
void AVL_Tree::inorder()
{
    inorderrec(root);
}

void AVL_Tree::preorderrec(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->data<<" ";
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void AVL_Tree::preorder()
{
    preorderrec(root);
}



int main()
{
    AVL_Tree T;
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

    cout << "Deleting element 60" << endl;
    T.Delete(60);
    cout << "Inorder traversal after deleting 50: ";
    T.inorder();
    cout << endl;

    cout << "Deleting element 40" << endl;
    T.Delete(40);
    cout << "Inorder traversal after deleting 50: ";
    T.inorder();
    cout << endl;

    return 0;
    return 0;
}