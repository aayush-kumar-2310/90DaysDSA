#include<bits/stdc++.h>
using namespace std;

int fastSearch(vector<int> &arr, int l, int r){

int l1 = -2, l2 = -2;
    if(l < arr[0])
        l1 = 1;
        
    else if(l > arr[arr.size()-1] or r < arr[0])
        return 0;
        
    int s = 0, e = arr.size()-1;

    while(s <= e){

        int mid = s + (e-s)/2;

        if(arr[mid] == l){
            l1 = mid+1;
            e = mid-1;
        }

        else if(arr[mid] > l)
            e = mid-1;
        else
            s = mid+1;
    }
    if(l1 == -2)
        l1 = s+1;
    
    s = 0, e = arr.size()-1;

    while(s <= e){

        int mid = s + (e-s)/2;

        if(arr[mid] == r){
            l2 = mid+1;
            s = mid+1;
        }

        else if(arr[mid] > r)
            e = mid-1;
        else
            s = mid+1;
    }

    if(l2 == -2)
        l2 = e+1;

    return l2-l1+1;

}



int main(){

    int size, k;
    cin>>size;
    vector<int> arr;

    for(int i = 0; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    
    sort(arr.begin(), arr.end());

    cin>>k;
    
    for(int i =0; i<k; i++){
        int l, r;
        cin>>l>>r;
        cout<<fastSearch(arr, l ,r)<<" ";
    }
}