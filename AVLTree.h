//inclusions
#include <fstream>
// tree node
#include "TreeNode.h"

template <class T>
class AVLTree {
    protected:
        TreeNode<T>* root;
        unsigned int size;
    public:
        AVLTree();
        ~AVLTree();

        bool insert(T data);
        T remove(T data);
        T find(T data);

        bool contains(T data);
        bool isEmpty();
        bool isLeafNode(TreeNode<T>* node);

        TreeNode<T>* getRoot();

        void printTree(); // default in-order
        void rec_print(TreeNode<T>* node, char order); // default in-order
};

template <class T>
TreeNode<T>* AVLTree<T>::getRoot() {
    return root;
}