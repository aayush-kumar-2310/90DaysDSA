#include<bits/stdc++.h>
using namespace std;

int floor(vector<int> &v, int key){
    
    if(key < v[0]) // IF THE KEY IS SMALLER THAN THE SMALLEST NUMBER IN THE ARRAY
        return -1;
    
    int start = 0;
    int end = v.size()-1;

    while(start<=end){

        int mid = start + (end-start)/2;

        if(v[mid] == key)
            return v[mid];

        else if(v[mid] < key){
            start = mid+1;
        }

        else if(v[mid] > key){
            end = mid-1;
        }
    }
    return v[end];
}

int main(){

    vector<int> v {2,3,5,9,14,16,18};
    cout<<floor(v, 100);
}