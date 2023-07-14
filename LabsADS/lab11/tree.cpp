#include<iostream>
#include "tree.h"
using namespace std;

void tests() {
    Tree<int> T;
    T.insert(14);
    T.insert(11);
    T.insert(4);
    T.insert(9);
    
    TreeNode<int>* root = T.getRoot();
    if (root->right->value == 14&&root->value==11&&root->left->value==4) {
        std::cout << "test passed\n";
    }
    else std::cout << "test failed\n";

    if (T.getHeight() == 2) {
        std::cout << "test 1 passed\n";
    }
    else std::cout << "test 1 failed\n";
    T.insert(7);
    T.insert(1);
    T.insert(3);
    T.insert(6);
    
    if (T.getHeight() == 3) {
        std::cout << "test 2 passed\n";
    }
    else std::cout << "test 2 failed\n";
    T.remove(7);
    T.remove(3);
    if (T.getHeight() == 2) {
        std::cout << "test 3 passed\n";
    }
    else std::cout << "test 3 failed\n";
    T.print();
    std::cout << "preorder: ";
    T.preorder(T.getRoot());
    std::cout << "\npostorder: ";
    T.postorder(T.getRoot());
    if (T.getBalance(T.getRoot()) == 0) {
        std::cout << "\ntest 4 passed\n";
    }
    else std::cout << "\ntest 4 failed\n";
    if (T.getRootVal() == 9) {
        std::cout << "test 5 passed\n";
    }
    else std::cout << "test 5 failed\n";


}


int main()
{
    tests();

    return 0;
}