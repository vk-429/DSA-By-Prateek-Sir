#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
    node *left;
    int value;
    node *right;
    node() : left(nullptr), right(nullptr), value(0) {}
    node(int val) : left(nullptr), right(nullptr), value(val) {}
};

class tree
{
    private:
        node *root;
        vector<node *> vec;
        int curr;

    public:
        tree() : root(nullptr), curr(0) {}
        void insert(int);
        void spiral_order_traversal();
        
};

void tree::insert(int val)
{
    node *temp = new node(val);
    if (root == nullptr)
    {
        vec.push_back(temp);
        root = vec[curr];
    }
    else
    {
        if (vec[curr]->left == nullptr)
        {
            vec[curr]->left = temp;
            vec.push_back(temp);
        }
        else if (vec[curr]->right == nullptr)
        {
            vec[curr]->right = temp;
            vec.push_back(temp);
        }

        // Move to the next node in vec if both children are filled
        if (vec[curr]->left != nullptr && vec[curr]->right != nullptr)
        {
            curr++;
        }
    }
}

void tree::spiral_order_traversal()
{
    stack<node *> s1, s2;
    if (root == nullptr)
        return;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *temp = s1.top();
            s1.pop();
            cout << temp->value << " ";
            if (temp->right != nullptr)
                s2.push(temp->right);
            if (temp->left != nullptr)
                s2.push(temp->left);
        }
        while (!s2.empty())
        {
            node *temp = s2.top();
            s2.pop();
            cout << temp->value << " ";
            if (temp->left != nullptr)
                s1.push(temp->left);
            if (temp->right != nullptr)
                s1.push(temp->right);
        }
    }
    cout << "\n";
}

int main()
{
    tree t1;
    int n;
    cout << "Enter No. of Nodes : ";
    cin >> n;
    cout << "Enter Values :-\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t1.insert(x);
    }
    t1.spiral_order_traversal();
    return 0;
}
