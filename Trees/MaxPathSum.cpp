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

int maxPathDown(node* root, int& maxSum){
    
    if(root == NULL)
        return 0;

    int leftSum = max(0, maxPathDown(root->left, maxSum));
    int rightSum = max(0,maxPathDown(root->right, maxSum));

    maxSum = max(maxSum, root->val + leftSum + rightSum);

    return max(leftSum , rightSum) + root->val;
}

int maxPathSum(node* root){

    int maxSum = INT_MIN;
    maxPathDown(root, maxSum);
    return maxSum;
}



int main(){

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);

    node* root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    cout<<maxPathSum(root);
    
    
    cout<<maxPathSum(root2);
  
}