#include<bits/stdc++.h>
using namespace std;

int ceiling(vector<int> &v, int key){
    
    double d = -DBL_
    if(key > v[v.size()-1]) // // IF THE KEY IS GREATER THAN THE GREATEST NUMBER IN THE ARRAY
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
    return v[start];
}

int main(){

    vector<int> v {2,3,5,9,14,16,18};
    cout<<ceiling(v, 0);
}