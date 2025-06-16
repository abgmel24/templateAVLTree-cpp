//inclusions
#include <fstream>
// tree node
#include "TreeNode.h"

template <class T>
class AVLTree {
    protected:
        TreeNode<T>* root;
        unsigned int size;

        /* int balanceFactor is the difference between left and right node of the tree
        -1 means left side is longer
        0 means one side is both are equal
        1 means right side is longer
        < -1 or > 1 means tree needs to rebalance (should never STAY this value if tree works properly) 
        */
        int balanceFactor; //no need to track node heights, just their difference!
    public:
        AVLTree();
        ~AVLTree();

        bool insert(T data);
        T remove(T data);
        T find(T data);

        bool contains(T data);
        bool isEmpty();

        TreeNode<T>* getRoot();

        void printTree(); // default in-order
        void rec_print(TreeNode<T>* node); // default in-order

        void rotate(TreeNode<T>* node);
};

template <class T>
void insert(T data) {
    //edge case if tree is empty
    if(this->isEmpty()) {
        root->key = data;
        //balance factor stays 0 because left_height = right_height = 0;
    }
    //else find node to insert
    
    //change balanceFactor based on which side of the tree to insert on
    if(data < root->key) { //insert will be on left side of tree
        balanceFactor--;
    } else {
        balanceFactor++;
    }

    TreeNode<T>* curr = this->root;
    TreeNode<T>* parent = NULL;
    ////iterating to find insert node + inserting
    while(curr) {
        parent = curr;
        if(curr->key < data) { 
            curr = curr->left;
        } else if(curr->key > data) {
            curr = curr->right;
        }
    }

    if(data < parent->key) {
        parent->left = new TreeNode(data);
        this->size++;
    } else {
        parent->right  = new TreeNode(data);
        this->size++;
    }

    //check heights and rebalance
    if(balanceFactor <= -2 || balanceFactor >= -2) {
        rotate(root);
    }


    return true;
}

template <class T>
T remove(T data) {

}

template <class T>
T find(T data) {

}

template <class T>
bool contains(T data) {
    return true;
}

template <class T>
void AVLTree<T>::rotate(TreeNode<T>* node) {
    //rebalance the tree

    //resetting balanceFactor
    if(this->size % 2 = 1) {
        balanceFactor = 0;
    } else {
        //how do you know whether left or right is longer?
    }

}

template <class T>
AVLTree<T>::AVLTree() {
    root = new TreeNode<T>();
    size = 0;
    balanceFactor = 0;
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
void AVLTree<T>::printTree() { // default in-order
    rec_print(root);
}

template <class T>
void AVLTree<T>::rec_print(TreeNode<T>* node) { // default in-order
    if(node->isLeafNode()) {
        cout << node->key << endl;
    }

    rec_print(node->left);
    cout << node->key << endl;
    rec_print(node->right);
}