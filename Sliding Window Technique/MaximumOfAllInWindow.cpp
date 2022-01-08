#include<bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &v, int k){

    int p1 = 0, p2 = 0;
    vector<int> ans;
    deque<int> dq;

    while(p2 < v.size()){
        
        while(p2-p1 != k-1){
         
            if(dq.empty()){
            dq.push_back(v[p2]);
            p2++;
            }

            else if(dq.front() < v[p2]){
            dq.clear();
            dq.push_front(p2);
            p2++;
            }

            else{
            dq.push_back(p2);
            p2++;
            }
        }

        if(v[p2] > dq.front())
        
    }

}

int main(){

    int size, k;
    cin>>size>>k;
    vector<int> v;

    for(int i = 0; i<size; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }



}