#include<bits/stdc++.h>
using namespace std;

void NextSmallerElementToLeft(vector<int> &ans, vector<int> &arr){

    stack<int> st;
    for(int i = 0; i<arr.size(); i++){

        while( !st.empty() and arr[i] <= st.top())
            st.pop();

        if(st.empty()){
            ans.push_back(-1);
            st.push(arr[i]);
        }

        else{
            ans.push_back(st.top());
            st.push(arr[i]);
        }
    }
}


int main(){

    int n;
    cin>>n;
    vector<int> arr, ans;
    for(int i =0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    NextSmallerElementToLeft(ans, arr);
    
    for(auto x:ans)
        cout<<x<<" ";
}