#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<int> st;
    vector<int> arr, LSE, RSE;

    int size, ans = 0; 
    cin>>size;

    for(int i=0; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i=0; i<arr.size(); i++){

        while( !st.empty() and arr[st.top()] >= arr[i])
            st.pop();

        if(st.empty()){
            LSE.push_back(-1);
            st.push(i);
        }

        else{            
            LSE.push_back(st.top());
            st.push(i);
        }
    }

    while(!st.empty())
        st.pop();
    
    for(int i=arr.size()-1; i>= 0; i--){

        while( !st.empty() and arr[st.top()] >= arr[i])
            st.pop();

        if(st.empty()){
            RSE.push_back(arr.size());
            st.push(i);
        }

        else{            
            RSE.push_back(st.top());
            st.push(i);
        }
    }

    reverse(RSE.begin(), RSE.end());

    for(int i =0; i<arr.size(); i++){
        ans = max(ans, (RSE[i] - (LSE[i] + 1))*arr[i]);
    }

    cout<<ans;
}