#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>& v, int pos){

    if(pos == 1)
        return;
    
    for(int i=0; i<pos-1; i++){
        if(v[i]>v[i+1])
            swap(v[i], v[i+1]);
    }
    BubbleSort(v, --pos);
    return;
}

int main(){

    int size;
    cin>>size;

    vector<int> v;

    for(int i=0; i<size; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    BubbleSort(v, v.size());

    for(auto x:v)
        cout<<x<<" ";
}