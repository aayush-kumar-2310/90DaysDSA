#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left = NULL;
    node* right = NULL;

    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

int height(node* root){

    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

bool isBalanced(node* root){

    if(root == NULL)
            return true;

    int lh = height(root->left);
    int rh = height(root->right);


    return abs(lh - rh) <= 1 and isBalanced(root->left) and isBalanced(root->right); 
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    cout<<height(root);
}