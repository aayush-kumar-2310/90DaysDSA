#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left = NULL;
    node* right = NULL;

    node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

void preOrderTraversal(node* root){

    if(root == NULL)
        return;

    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void preOrderTraversalIterative(node* root){

    if(root == NULL)
        return;

    stack<node*> st;
    st.push(root);

    while( !st.empty()){
        root = st.top();
        st.pop();
        cout<<root->val<<" ";

        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
}

int main(){

    node* root = new node(10);
    root->left = new node(11);
    root->right = new node(-20);
    root->right->right = new node(9);
    root->right->left = new node(0);
    root->right->left->left = new node(16);
    root->right->left->right = new node(18);
    root->left->right = new node(12);
    root->left->left = new node(15);

    // preOrderTraversal(root);
    preOrderTraversalIterative(root);

}