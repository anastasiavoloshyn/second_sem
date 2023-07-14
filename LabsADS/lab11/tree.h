#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct TreeNode {
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
    int height;

    TreeNode();
    TreeNode(T val);
    TreeNode(T val, TreeNode<T>* l, TreeNode<T>* r, int h);
};

template<typename T>
TreeNode<T>::TreeNode() : value(0), left(nullptr), right(nullptr), height(0) {}

template<typename T>
TreeNode<T>::TreeNode(T val) : value(val), left(nullptr), right(nullptr), height(0) {}

template<typename T>
TreeNode<T>::TreeNode(T val, TreeNode<T>* l, TreeNode<T>* r, int h)
    : value(val), left(l), right(r), height(h) {}

template<typename T>
class Tree {
private:
    TreeNode<T>* root;
    TreeNode<T>* insert(T val, TreeNode<T>* t);//
    TreeNode<T>* rightRotate(TreeNode<T>*& t);//
    TreeNode<T>* leftRotate(TreeNode<T>*& t);//
    TreeNode<T>* leftAndRightRotate(TreeNode<T>*& t);//
    TreeNode<T>* rightAndLeftRotate(TreeNode<T>*& t);//
    TreeNode<T>* findMin(TreeNode<T>* t);//
    TreeNode<T>* findMax(TreeNode<T>* t);//
    TreeNode<T>* remove(T val, TreeNode<T>* t);
    void empty(TreeNode<T>* t);//
    int height(TreeNode<T>* t);

public:
    Tree();
    ~Tree();
    int getHeight();
    void insert(T val);
    void remove(T val);
    void print();
    TreeNode<T>* getRoot() {
        return root;
    }
    T getRootVal() {
        return root->value;
    }
    int getBalance(TreeNode<T>* t);
    void inorder(TreeNode<T>* t);
    void postorder(TreeNode<T>* t);
    void preorder(TreeNode<T>* t);
};

template<typename T>
TreeNode<T>* Tree<T>::insert(T val, TreeNode<T>* t) {
    if (t == nullptr) {
        t = new TreeNode<T>(val);
    }
    else if (val > t->value) {
        t->right = insert(val, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (val > t->right->value) {
                t = leftRotate(t);
            }
            else {
                t = leftAndRightRotate(t);
            }
        }
    }
    else if (val < t->value) {
        t->left = insert(val, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (val < t->left->value) {
                t = rightRotate(t);
            }
            else {
                t = rightAndLeftRotate(t);
            }
        }
    }
    int maximum = max(height(t->left), height(t->right));
    t->height = maximum + 1;
    return t;
}

template<typename T>
TreeNode<T>* Tree<T>::rightRotate(TreeNode<T>*& t) {
    TreeNode<T>* temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    temp->height = max(height(temp->left), t->height) + 1;
    return temp;
}

template<typename T>
TreeNode<T>* Tree<T>::leftRotate(TreeNode<T>*& t) {
    TreeNode<T>* temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    temp->height = max(height(t->right), t->height) + 1;
    return temp;
}

template<typename T>
TreeNode<T>* Tree<T>::leftAndRightRotate(TreeNode<T>*& t) {
    t->right = rightRotate(t->right);
    return leftRotate(t);
}

template<typename T>
TreeNode<T>* Tree<T>::rightAndLeftRotate(TreeNode<T>*& t) {
    t->left = leftRotate(t->left);
    return rightRotate(t);
}

template<typename T>
TreeNode<T>* Tree<T>::findMin(TreeNode<T>* t) {
    if (t == nullptr) {
        std::cout << "AVL Tree is empty\n";
        return 0;
    }
    else if (t->left == nullptr) {
        return t;
    }
    else {
        return findMin(t->left);
    }
}

template<typename T>
TreeNode<T>* Tree<T>::findMax(TreeNode<T>* t) {
    if (t == nullptr) {
        std::cout << "AVL Tree is empty\n";
        return 0;
    }
    else if (t->right == nullptr) {
        return t;
    }
    else {
        return findMax(t->right);
    }
}

template<typename T>
TreeNode<T>* Tree<T>::remove(T val, TreeNode<T>* t) {
    TreeNode<T>* temp;
    if (t == nullptr) {
        return 0;
    }
    else if (val > t->value) {
        t->right = remove(val, t->right);
    }
    else if (val < t->value) {
        t->left = remove(val, t->left);
    }
    else if (t->left && t->right) {
        temp = findMin(t->right);
        t->value = temp->value;
        t->right = remove(t->value, t->right);
    }
    else {
        temp = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }
    if (t == nullptr) {
        return t;
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    if (height(t->left) - height(t->right) == 2) {
        if (height(t->left->left) - height(t->left->right) != 1) {
            return leftAndRightRotate(t);
        }
        else {
            return leftRotate(t);
        }
    }
    else if (height(t->right) - height(t->left) == 2) {
        if (height(t->right->right) - height(t->right->left) != 1) {
            return rightAndLeftRotate(t);
        }
        else {
            return rightRotate(t);
        }
    }
    return t;
}

template<typename T>
void Tree<T>::empty(TreeNode<T>* t) {
    if (t == nullptr) {
        return;
    }
    else {
        TreeNode<T>* temp;
        empty(t->left);
        empty(t->right);
        temp = t;
        delete temp;
        t = nullptr;
    }
}

template<typename T>
int Tree<T>::height(TreeNode<T>* t) {
    if (t == nullptr) {
        return -1;
    }
    else {
        return t->height;
    }
}

template<typename T>
int Tree<T>::getBalance(TreeNode<T>* t) {
    if (t == nullptr) {
        return 0;
    }
    else {
        return height(t->left) - height(t->right);
    }
}

template<typename T>
void Tree<T>::inorder(TreeNode<T>* t) {
    if (t == nullptr) {
        return;
    }
    else {
        inorder(t->left);
        cout << t->value << ", ";
        inorder(t->right);
    }
}

template<typename T>
void Tree<T>::postorder(TreeNode<T>* t) {
    if (t == nullptr) {
        return;
    }
    else {
        postorder(t->left);
        postorder(t->right);
        cout << t->value << ", ";
    }
}

template<typename T>
void Tree<T>::preorder(TreeNode<T>* t) {
    if (t == nullptr) {
        return;
    }
    else {
        cout << t->value << ", ";
        preorder(t->left);
        preorder(t->left);
    }
}

template<typename T>
Tree<T>::Tree() {
    root = nullptr;
}

template<typename T>
Tree<T>::~Tree() {
    empty(root);
}

template<typename T>
int Tree<T>::getHeight() {
    if (!root) {
        return -1;
    }
    else {
        return root->height;
    }
}

template<typename T>
void Tree<T>::insert(T val) {
    root = insert(val, root);
}

template<typename T>
void  Tree<T>::remove(T val) {
    root = remove(val, root);
}

template<typename T>
void  Tree<T>::print() {
    inorder(root);
    cout << "\n";
}

