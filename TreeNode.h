#include <iostream>
#include <exception>

template <class T>
class TreeNode {
    public:
        TreeNode() {}
        TreeNode(T data) {
            key = data;
        }
        ~TreeNode() {
            delete left;
            delete right;
        }

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;
};