#include<bits/stdc++.h>
using namespace std;

int main(){

    int size;
    stack<int> st;
    

    cin>>size;
    vector<int> arr, LSE(size), RSE(size);
    for(int i =0; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i = 0; i<size; i++){
        
        while( !st.empty() and arr[st.top()] >= arr[i] ){
            RSE[st.top()] = i;
            st.pop();
        }
            

        if( st.empty()){
            LSE[i] = -1;
            st.push(i);
        }

        else{
            LSE[i] = st.top();
            st.push(i);
        }
    }

    while( !st.empty()){
        RSE[st.top()] = size;
        st.pop();
    }


    
    int maxAr = 0;

    for(int i = 0; i<size; i++)
        maxAr = max(maxAr, (RSE[i] - (LSE[i] + 1))*arr[i] );

    cout<<maxAr;
}