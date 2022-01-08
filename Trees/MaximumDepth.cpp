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

int maxDepth(node* root){

    if(root == NULL)
        return 0;

    int c = 0;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        c++;
        for(int i = 0; i<size; i++){
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
    }
    return c;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->right = new node(6);
    root->right->left = new node(4);
    root->right->left->left = new node(5);

    cout<<maxDepth(root);
}