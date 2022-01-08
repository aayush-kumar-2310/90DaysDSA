#include<bits/stdc++.h>
using namespace std;

void firstNegativeNumberInWindow(vector<int> &arr, vector<int> &ans, int k){

    int p1 = 0, p2 = 0;
    queue<int> q;

    while(p2 != arr.size()){

        while(p2-p1 != k-1){
            if(arr[p2] < 0)
                q.push(arr[p2]);

            p2++;
        }

        if(arr[p2] < 0)
            q.push(arr[p2]);

        if(q.empty())
            ans.push_back(0);
        else    
            ans.push_back(q.front());

        if(arr[p1] == q.front())
            q.pop();
        p1++;
        p2++;
    }
}

int main(){

    int size, k;
    cin>>size>>k;
    vector<int> arr, ans;

    for(int i = 0; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    firstNegativeNumberInWindow(arr, ans, k);

    for(auto x:ans)
        cout<<x<<" ";
}