#include<bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node* left = NULL;
    node* right = NULL;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrderTraversal(node* root){

    if(root == NULL)
        return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void inOrderTraversalIterative(node* root){

    if(root == NULL)
        return;

    stack<node*> st;

    while(1){
        if(root != NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty()) break;

            root = st.top();
            st.pop();
            cout<<root->data<<" ";
            root = root->right;
        }
    }
}

int main(){

    node* root = new node(10);
    root->left = new node(11);
    root->right = new node(16);
    root->left->left = new node(2);
    root->left->right = new node(-1);
    root->right->left = new node(10);
    root->right->left->left = new node(9);
    root->right->left->right = new node(11);


    inOrderTraversalIterative(root);
}