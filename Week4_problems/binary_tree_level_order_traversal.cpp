// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
#include <iostream>
#include <queue>
using namespace std;

// Node structure definition
struct node {
    int data;
    node *left, *right;
};

// Function to create a new node with given data
node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// Function to perform level order traversal using queue
void printLevelOrder(node* root) {
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<node*> q;

    // Enqueue the root and initialize height
    q.push(root);

    while (!q.empty()) {
        // Print front of queue and remove it from queue
        node* tempNode = q.front();
        cout << tempNode->data << " ";
        q.pop();

        // Enqueue left child
        if (tempNode->left != NULL)
            q.push(tempNode->left);

        // Enqueue right child
        if (tempNode->right != NULL)
            q.push(tempNode->right);
    }
}

// Main function to test above functions
int main() {
    // Constructing the binary tree given in the problem statement
    node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}
