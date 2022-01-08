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

void postOrderTraversal(node* root){

    if(root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}                               

void postOrderTraversalIterative(node* root){

    if(root == NULL)
        return ;

    stack<node*> st1, st2;

    st1.push(root);

    while( !st1.empty()){

        st2.push(st1.top());
        st1.pop();

        if(st2.top()->left != NULL) st1.push(st2.top()->left);
        if(st2.top()->right != NULL) st1.push(st2.top()->right);

    }

    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }

}

void postOrderTraversal2(node* root){

    if(root == NULL)
        return;

    stack<int> st;

    

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->left->right = new node(7);
    root->right->left->right->right = new node(8);

    postOrderTraversal(root);

}