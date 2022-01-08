#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<int> index;

    int size;
    cin>>size;

    vector<int> arr, ans;

    for(int i =0; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    
    for(int i =0; i<arr.size(); i++){

        while( !index.empty() and arr[i] >= arr[index.top()])
            index.pop();

        if(index.empty()){
            ans.push_back(i - 0 + 1);
            index.push(i);
        }

        else{
            ans.push_back(i - index.top());
            index.push(i);
        }
        
    }

    for(auto x:ans)
        cout<<x<<" ";

}