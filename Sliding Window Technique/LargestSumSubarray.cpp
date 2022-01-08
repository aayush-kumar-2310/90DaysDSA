#include<bits/stdc++.h>
using namespace std;

int largestSumSubarray(vector<int> &v, int k){

    int p1 = 0, p2 = 0, tmp = 0, sum = 0;

    while(p2 != v.size()){

        while(p2-p1 != k-1){
            tmp += v[p2];
            p2++;
        }

        tmp+=v[p2];
        sum = max(sum, tmp);
        tmp -= v[p1];
        p1++;
        p2++;
    }
    return sum;
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

    cout<<largestSumSubarray(v, k);
        
    
    

}