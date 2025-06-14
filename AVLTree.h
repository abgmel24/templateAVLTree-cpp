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

        TreeNode<T>* getRoot();

        void printTree(char order[2]); // default in-order
        void rec_print(TreeNode<T>* node, char order[2]); // default in-order
};

template <class T>
AVLTree<T>::AVLTree() {
    root = new TreeNode<T>();
    size = 0;
}

template <class T>
AVLTree<T>::~AVLTree() {
    //removing every node (deletes the data)
    while(this->size > 0) {
        cout << "deleting node" << remove(this->root->key) << endl;
    }
    delete this->root; //frees up memory
}


template <class T>
TreeNode<T>* AVLTree<T>::getRoot() {
    return root;
}

template <class T>
bool AVLTree<T>::isEmpty() {
    return size == 0; //tree is empty if size 0; false otherwise
}

template <class T>
void AVLTree<T>::printTree(char order[2] = "in") { // default in-order
    rec_print(root, order);
} 

template <class T>
void rec_print(TreeNode<T>* node, char order[2] = "in") { // default in-order
    if(order == "in") {
        rec_print_in_order(node);
    } else if(order == "")
}    

bool insert(T data);
T remove(T data);
T find(T data);

bool contains(T data);