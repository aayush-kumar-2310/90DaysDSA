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

vector<vector<int>> levelOrderTraversal(node* root){

    vector<vector<int>> ans;

    if(root == NULL)
        return ans;

    queue<node*> q;
    q.push(root);

    while( !q.empty()){

        vector<int> arr;
        int size = q.size();

        for(int i =0; i<size; i++){
            arr.push_back(q.front()->val);
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);  
            q.pop();
        }
        ans.push_back(arr);
    }

    return ans;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> ans = levelOrderTraversal(root);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++)
            cout<<ans[i][j];
        cout<<endl;
    }
}