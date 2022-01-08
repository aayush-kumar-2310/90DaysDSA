#include<bits/stdc++.h>
using namespace std;

struct Node{

    int val;
    Node* left;
    Node* right;

    public:

    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inOrderTraversal(Node* root){

        if(root == NULL)
            return;

        inOrderTraversal(root->left);
        cout<<root->val<<" ";
        inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){

        if(root == NULL)
            return;

        cout<<root->val<<" ";
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){

        if(root == NULL)
            return;

        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        cout<<root->val<<" ";
}

int main(){

    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);

    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
}