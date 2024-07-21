#include <iostream>
using namespace std;

const int DEGREE = 5; // B-Tree degree

class BTreeNode {
public:
    int *keys;
    int degree;
    BTreeNode **children;
    int n; // Current number of keys
    bool leaf; // Is true when the node is leaf. Otherwise false

    BTreeNode(bool leaf);

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode *y);
    void traverse();

    BTreeNode *search(int key);

    int findKey(int key);

    void remove(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);

    int getPred(int idx);
    int getSucc(int idx);

    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    friend class BTree;
};

class BTree {
public:
    BTreeNode *root;
    int degree;

    BTree() {
        root = NULL;
        degree = DEGREE;
    }

    void traverse() {
        if (root != NULL) root->traverse();
    }

    BTreeNode* search(int key) {
        return (root == NULL) ? NULL : root->search(key);
    }

    void insert(int key);
    void remove(int key);
};

BTreeNode::BTreeNode(bool leaf1) {
    degree = DEGREE;
    leaf = leaf1;

    keys = new int[2 * degree - 1];
    children = new BTreeNode *[2 * degree];

    n = 0;
}

int BTreeNode::findKey(int key) {
    int idx = 0;
    while (idx < n && keys[idx] < key)
        ++idx;
    return idx;
}

void BTreeNode::remove(int key) {
    int idx = findKey(key);

    if (idx < n && keys[idx] == key) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else {
        if (leaf) {
            cout << "The key " << key << " is does not exist in the tree\n";
            return;
        }

        bool flag = ((idx == n) ? true : false);

        if (children[idx]->n < degree)
            fill(idx);

        if (flag && idx > n)
            children[idx - 1]->remove(key);
        else
            children[idx]->remove(key);
    }
    return;
}

void BTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];
    n--;
    return;
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];

    if (children[idx]->n >= degree) {
        int pred = getPred(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    }
    else if (children[idx + 1]->n >= degree) {
        int succ = getSucc(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    }
    else {
        merge(idx);
        children[idx]->remove(key);
    }
    return;
}

int BTreeNode::getPred(int idx) {
    BTreeNode *cur = children[idx];
    while (!cur->leaf)
        cur = cur->children[cur->n];
    return cur->keys[cur->n - 1];
}

int BTreeNode::getSucc(int idx) {
    BTreeNode *cur = children[idx + 1];
    while (!cur->leaf)
        cur = cur->children[0];
    return cur->keys[0];
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->n >= degree)
        borrowFromPrev(idx);
    else if (idx != n && children[idx + 1]->n >= degree)
        borrowFromNext(idx);
    else {
        if (idx != n)
            merge(idx);
        else
            merge(idx - 1);
    }
    return;
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode *child = children[idx];
    BTreeNode *sibling = children[idx - 1];

    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }

    child->keys[0] = keys[idx - 1];

    if (!child->leaf)
        child->children[0] = sibling->children[sibling->n];

    keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;

    return;
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode *child = children[idx];
    BTreeNode *sibling = children[idx + 1];

    child->keys[(child->n)] = keys[idx];

    if (!(child->leaf))
        child->children[(child->n) + 1] = sibling->children[0];

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }

    child->n += 1;
    sibling->n -= 1;

    return;
}

void BTreeNode::merge(int idx) {
    BTreeNode *child = children[idx];
    BTreeNode *sibling = children[idx + 1];

    child->keys[degree - 1] = keys[idx];

    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + degree] = sibling->keys[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->children[i + degree] = sibling->children[i];
    }

    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    for (int i = idx + 2; i <= n; ++i)
        children[i - 1] = children[i];

    child->n += sibling->n + 1;
    n--;

    delete (sibling);
    return;
}

void BTree::insert(int key) {
    if (root == NULL) {
        root = new BTreeNode(true);
        root->keys[0] = key;
        root->n = 1;
    } else {
        if (root->n == 2 * degree - 1) {
            BTreeNode *s = new BTreeNode(false);
            s->children[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < key)
                i++;
            s->children[i]->insertNonFull(key);

            root = s;
        } else
            root->insertNonFull(key);
    }
}

void BTreeNode::insertNonFull(int key) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->n == 2 * degree - 1) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->leaf);
    z->n = degree - 1;

    for (int j = 0; j < degree - 1; j++)
        z->keys[j] = y->keys[j + degree];

    if (!y->leaf) {
        for (int j = 0; j < degree; j++)
            z->children[j] = y->children[j + degree];
    }

    y->n = degree - 1;

    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[degree - 1];

    n = n + 1;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    if (!leaf)
        children[i]->traverse();
}

BTreeNode *BTreeNode::search(int key) {
    int i = 0;
    while (i < n && key > keys[i])
        i++;

    if (keys[i] == key)
        return this;

    if (leaf)
        return NULL;

    return children[i]->search(key);
}

void BTree::remove(int key) {
    if (!root) {
        cout << "The tree is empty\n";
        return;
    }

    root->remove(key);

    if (root->n == 0) {
        BTreeNode *tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->children[0];

        delete tmp;
    }
    return;
}

int main() {
    BTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of tree constructed:\n";
    t.traverse();
    cout << endl;

    t.remove(6);
    cout << "Traversal of tree after removing 6:\n";
    t.traverse();
    cout << endl;

    t.remove(13);
    cout << "Traversal of tree after removing 13:\n";
    t.traverse();
    cout << endl;

    t.remove(7);
    cout << "Traversal of tree after removing 7:\n";
    t.traverse();
    cout << endl;

    t.remove(4);
    cout << "Traversal of tree after removing 4:\n";
    t.traverse();
    cout << endl;

    t.remove(2);
    cout << "Traversal of tree after removing 2:\n";
    t.traverse();
    cout << endl;

    t.remove(16);
    cout << "Traversal of tree after removing 16:\n";
    t.traverse();
    cout << endl;

    return 0;
}
