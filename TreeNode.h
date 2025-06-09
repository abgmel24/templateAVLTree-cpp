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
        bool isLeafNode() {
            return (left == NULL) && (right == NULL);
        }

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;
};