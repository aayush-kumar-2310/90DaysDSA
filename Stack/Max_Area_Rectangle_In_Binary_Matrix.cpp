#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> &arr){

    stack<int> st;
    vector<int> LSE(arr.size()), RSE(arr.size());

    for(int i= 0; i<arr.size(); i++){
        while( !st.empty() and arr[st.top()] >= arr[i]){
            RSE[st.top()] = i;
            st.pop();
        }

        if(st.empty()){
            LSE[i] = -1;
            st.push(i);
        }

        else{
            LSE[i] = st.top();
            st.push(i);
        }
    }
    
    while( !st.empty()){
        RSE[st.top()] = arr.size();
        st.pop();
    }

    int maxAr = 0;

    for(int i = 0; i<arr.size(); i++)
        maxAr = max(maxAr, (RSE[i] - (LSE[i] + 1))*arr[i]);
    
    return maxAr;
}

int main(){

    int row, col;
    cin>>row>>col;
    int ans = 0;
    int arr[row][col];
    vector<int> matRow;
    
    for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
            cin>>arr[i][j];
    
    for(int i =0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(i == 0){
                matRow.push_back(arr[i][j]);
            }
            else{
                if(arr[i][j] == 1)
                    matRow[j] += 1;
                else
                    matRow[j] = 0;
            }
        }
        ans = max(ans, getMaxArea(matRow));
    }
        
    cout<<"\nArea: "<<ans;
    
}