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

int heightOfTree(node* root){

    if(root == NULL)
        return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return max(lh, rh) + 1;
}

int h = 0;

int diameterOfTree(node* root){

    if(root == NULL)
        return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    h = max(lh + rh, h);
    diameterOfTree(root->left);
    diameterOfTree(root->right);
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->left->left = new node(5);
    root->right->left->left->left = new node(9);
    root->right->right = new node(6);
    root->right->right->right = new node(7);
    root->right->right->right->right = new node(8);

    cout<<diameterOfTree(root);
}