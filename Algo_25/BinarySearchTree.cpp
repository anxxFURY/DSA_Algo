//
// Created by Lenovo on 10/30/2022.
//

#include <iostream>
#include "algorithm"
#include "vector"
#include "list"
#include "utility"
#include "unordered_map"
#include "map"
#include "string"
using namespace std;

#define ll int
#define prlong  int(n) cout << n;
#define loop(n) for( int i = 0; i < n; i++)
#define rloop(n) for(long long int j = n-1; j>0; j--)

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node *root;
    void insert(Node *treeNode, int data);
    void insert(int data);
    bool isBalanced(Node *treeNode);
    Node * getmaxNode();
    Node * getminNode();
    int getHeight(Node *treeNode);
    void deleteBST(Node *treeNode);
    void inOrder(Node *treeNode);
    void preOrder(Node *treeNode);
    void postOrder(Node *treeNode);


    BST() {
        root = nullptr;
    }
};

void BST::insert(int data) {
    insert(root,data);
}

void BST::insert(Node *treeNode,int data) {
    if(!treeNode) {
        treeNode = new Node(data);
        root = treeNode;
    } else {
        if(data < treeNode->data) {
            if(!treeNode->left) {
                Node *temp = new Node(data);
                treeNode->left = temp;
            } else {
                insert(treeNode->left,data);
            }
        } else {
            if(!treeNode->right) {
                Node *temp = new Node(data);
                treeNode->right = temp;
            } else {
                insert(treeNode->right,data);
            }
        }
    }
}

void BST::deleteBST(Node *treeNode) {
    if(!treeNode)
        return;

    Node *curNode = treeNode;
    Node *leftNode = treeNode->left;
    Node *rightNode = treeNode->right;
    delete(curNode);
    deleteBST(leftNode);
    deleteBST(rightNode);
}

int BST::getHeight(Node *treeNode) {
    if(!treeNode)
        return 0;
    return  1 + max(getHeight(treeNode->left), getHeight(treeNode->right));
}

bool BST::isBalanced(Node *treeNode) {
    if(!treeNode)
        return false;
    int left = getHeight(treeNode->left);
    int right = getHeight(treeNode->right);

    if(abs(right-left) > 1)
        return false;
    return true;
}

Node *BST::getmaxNode() {
    if(!root)
        return nullptr;
     Node *treeNode = root;

     while(treeNode->right)
         treeNode = treeNode->right;
    return treeNode;
}

Node *BST::getminNode() {
    if(!root)
        return nullptr;
    Node *treeNode = root;

    while(treeNode->left)
        treeNode = treeNode->left;
    return treeNode;
}

void BST::inOrder(Node *treeNode) {
    if(!treeNode)
        return;
    inOrder(treeNode->left);
    cout << treeNode->data << " ";
    inOrder(treeNode->right);

    cout << endl;
}

void BST::preOrder(Node *treeNode) {
    if(!treeNode)
        return;
    cout << treeNode->data << " ";
    inOrder(treeNode->left);
    inOrder(treeNode->right);

    cout << endl;
}

void BST::postOrder(Node *treeNode) {
    if(!treeNode)
        return;
    inOrder(treeNode->left);
    inOrder(treeNode->right);
    cout << treeNode->data << " ";
    cout << endl;
}

int main () {

    BST bst;
    bst.insert(10);
    bst.insert(20);
    return 0;
}

