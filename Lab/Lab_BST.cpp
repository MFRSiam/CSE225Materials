#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinarySearchTree {
private:
    TreeNode* root;

    void insertNode(TreeNode*& tree, int data) {
        if (tree == NULL) {
            tree = new TreeNode;
            tree->data = data;
            tree->left = NULL;
            tree->right = NULL;
        }
        else if (data < tree->data) {
            insertNode(tree->left, data);
        }
        else {
            insertNode(tree->right, data);
        }
    }

    void printTree(TreeNode* tree) {
        if (tree == NULL) {
            return;
        }
        printTree(tree->left);
        cout << tree->data << ", ";
        printTree(tree->right);
    }

    int treeLength(TreeNode* tree) {
        if (tree == NULL) {
            return 0;
        }
        return 1 + treeLength(tree->left) + treeLength(tree->right);
    }

    bool findNode(TreeNode* tree, int data) {
        if (tree == NULL) {
            return false;
        }

        if (tree->data == data) {
            return true;
        }
        else if (data < tree->data) {
            return findNode(tree->left, data);
        }
        else {
            return findNode(tree->right, data);
        }
    }

    TreeNode* retrieveNode(TreeNode* tree, int data) {
        if (tree == NULL) {
            return NULL;
        }

        if (tree->data == data) {
            return tree;
        }
        else if (data < tree->data) {
            return retrieveNode(tree->left, data);
        }
        else {
            return retrieveNode(tree->right, data);
        }
    }

    void deleteNode(TreeNode*& tree, int data) {
        if (tree == NULL) {
            return;
        }
        if (tree->data == data) {
            if (tree->left == NULL && tree->right == NULL) {
                delete tree;
                tree = NULL;
            }
            else if (tree->left != NULL) {
                int maxLeftNode = findMaxNode(tree->left);
                tree->data = maxLeftNode;
                deleteNode(tree->left, maxLeftNode);
            }
            else {
                int minRightNode = findMinNode(tree->right);
                tree->data = minRightNode;
                deleteNode(tree->right, minRightNode);
            }
        }
        else if (tree->data < data) {
            deleteNode(tree->right, data);
        }
        else {
            deleteNode(tree->left, data);
        }
    }

    int findMinNode(TreeNode* tree) {
        if (tree == NULL) {
            return -1;
        }
        else if (tree->left == NULL) {
            return tree->data;
        }
        else {
            return findMinNode(tree->left);
        }
    }

    int findMaxNode(TreeNode* tree) {
        if (tree == NULL) {
            return -1;
        }
        else if (tree->right == NULL) {
            return tree->data;
        }
        else {
            return findMaxNode(tree->right);
        }
    }

    void makeEmpty(TreeNode*& tree) {
        if (tree == NULL) {
            return;
        }
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        delete tree;
        tree = NULL;
    }

    int getHeight(TreeNode* tree) {
        if (tree == NULL) {
            return 0;
        }
        int lsh = 1 + getHeight(tree->left);
        int rsh = 1 + getHeight(tree->right);

        if (lsh > rsh) {
            return lsh;
        }
        else {
            return rsh;
        }
    }

public:
    BinarySearchTree() {
        root = NULL;
    }
    void insertNode(int data) {
        insertNode(root, data);
    }

    void printTree() {
        printTree(root);
    }

    int treeLength() {
        treeLength(root);
    }

    TreeNode* retrieveNode(int data) {
        return retrieveNode(root, data);
    }

    bool findNode(int data) {
        return findNode(root, data);
    }

    void deleteNode(int data) {
        deleteNode(root, data);
    }

    int findMinNode() {
        findMinNode(root);
    }
    int findMaxNode() {
        findMaxNode(root);
    }

    bool isBalanced();

    void makeEmpty() {
        makeEmpty(root);
    }

    int getHeight() {
        getHeight(root);
    }

    bool isEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
};


void printManually(TreeNode* Node, int lvl) {
    if (Node == NULL) {
        return;
    }
    cout << "Level: " << lvl << " : " << Node->data << endl;
    printManually(Node->left, lvl + 1);
    printManually(Node->right, lvl + 1);

}
// void deleteFullTree(TreeNode* Node)
// {
//     if (Node == NULL){
//         return;
//     }

//     deleteFullTree(Node->left);
//     deleteFullTree(Node->right);
//     cout << "\n Deleting node: " << Node->data;
//     delete Node;
// }


int main() {
    // Create a binary search tree
    BinarySearchTree B1;
    // Insert nodes: 10, 5, 15, 2, 7, 13, 6, 8, 11, 17
    B1.insertNode(10);
    B1.insertNode(5);
    B1.insertNode(15);
    B1.insertNode(2);
    B1.insertNode(7);
    B1.insertNode(13);
    B1.insertNode(6);
    B1.insertNode(8);
    B1.insertNode(11);
    B1.insertNode(17);
    // Print the tree
    B1.printTree();
    // Print tree height
    cout << "Tree Height : " << B1.getHeight() << endl;
    // Print the minimum value in the tree
    cout << "Minimum Value in the Given Tree: " << B1.findMinNode() << endl;
    // Print the maximum value in the tree
    cout << "Maximum Value in the Given Tree: " << B1.findMaxNode() << endl;
    // Print the number of nodes in the tree
    cout << "The Number of Nodes in the Tree: " << B1.treeLength() << endl;
    // Manually print the nodes at each level (see example below)
    // cout << "Level 0: 10" << endl;
    TreeNode* getRoot = B1.retrieveNode(10);
    printManually(getRoot, 0);
    // Delete exactly two nodes to make the tree full and complete
    B1.deleteNode(11);
    // Print tree again
    B1.printTree();
    // Insert 8 more nodes but make sure that tree becomes full and complete
    B1.insertNode(1);
    B1.insertNode(3);
    B1.insertNode(12);
    B1.insertNode(14);
    B1.insertNode(16);
    B1.insertNode(18);
    B1.insertNode(4);
    B1.insertNode(9);
    // Print tree again
    cout << endl;
    B1.printTree();
    cout << endl;
    // Delete all the nodes in the tree Not The Optimal
    int a[] = { 10, 5, 15, 2, 7, 13, 6, 8, 17,1,3,12,14,16,18,4,9 };
    for (int i = 0; i < 17; i++) {
        B1.deleteNode(a[i]);
    }
    // Print 
    B1.printTree();
}