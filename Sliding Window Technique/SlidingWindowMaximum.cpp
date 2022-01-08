#include<bits/stdc++.h>
using namespace std;

int main(){

    int size, k; cin>>size>>k;
    int p1 = 0, p2 = 0;
    vector<int> arr, ans;
    deque<int> dq;

    for(int i =0 ; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    while( p2 != size){

        while(p2 - p1 != k-1){
            while(!dq.empty() and arr[dq.back()] <= arr[p2])
                dq.pop_back();

            dq.push_back(p2);
            p2++;
        }

        while( !dq.empty() and arr[p2] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(p2);

        ans.push_back(arr[dq.front()]);

        if(dq.front() == p1)
            dq.pop_front();

        p1++;
        p2++;
    }

    for(auto x:ans)
        cout<<x<<" ";
}