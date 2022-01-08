#include<bits/stdc++.h>
using namespace std;

void NextGreaterElement(vector<int> &ans, vector<int> &arr){

    stack<int> st;
    for(int i = arr.size()-1; i>=0; i--){

        while( !st.empty() and arr[i] >= st.top())
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

    reverse(ans.begin(), ans.end());
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

    NextGreaterElement(ans, arr);
    
    for(auto x:ans)
        cout<<x<<" ";
}