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

    void printNodesAtLevel(TreeNode* tree, int level) {
        if (tree == nullptr) {
            return;
        }
        else if (level == 1) {
            cout << tree->data << " ";
        }
        else if (level > 1) {
            printNodesAtLevel(tree->left, level - 1);
            printNodesAtLevel(tree->right, level - 1);
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

    bool findNode(int data) {
        return findNode(root, data);
    }

    int getHeight() {
        getHeight(root);
    }

    void printNodesAtLevel(int level) {
        printNodesAtLevel(root, level);
    }

    void printWholeTreeByLevel() {
        for (int i = 1; i <= getHeight(); i++) {
            cout << "Level " << i << " :";
            printNodesAtLevel(i);
            cout << endl;
        }
    }
};
/*
                10
                /\
               /  \
              /    \
             5     15
            / \    / \
           2   7  13  17
*/
int main() {
    // Create the binary tree shown above
    BinarySearchTree B1;

    // Insert the nodes exactly as shown above

    B1.insertNode(10);
    B1.insertNode(5);
    B1.insertNode(2);
    B1.insertNode(7);
    B1.insertNode(15);
    B1.insertNode(13);
    B1.insertNode(17);


    // Call printNodesAtLevel() function for each level separately


    //std::cout << B1.getHeight() << " and " << B1.treeLength() << std::endl;
    // The output for printNodesAtLevel(0) should be "Level 0: 10"
    // The output for printNodesAtLevel(1) should be "Level 1: 5, 15"
    // The output for printNodesAtLevel(2) should be "Level 2: 2, 7, 13, 17"
    for (int i = 1; i <= B1.getHeight(); i++) {
        cout << "Level " << i << " :";
        B1.printNodesAtLevel(i);
        cout << endl;
    }



    // Call the printWholeTreeByLevel() function
    // The output should be
    // Level 0: 10
    // Level 1: 5, 15
    // Level 2: 2, 7, 13, 17

    B1.printWholeTreeByLevel();

}