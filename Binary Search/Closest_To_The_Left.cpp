#include<bits/stdc++.h>
using namespace std;

void closestToLeft(vector<int> &arr, int k){

    int s = 0, e = arr.size()-1;
    int ans = 0;

    while(s <= e){

        int mid = s + (e-s)/2;

        if(arr[mid] == k){
            ans = mid+1;
            s = mid+1;
        }

        else if(arr[mid] > k)
            e = mid-1;
        else
            s = mid+1;
    }

    if(ans != 0)
        cout<<ans<<endl;
    else
        cout<<e+1<<endl;
}


int main(){

    int size, k;
    cin>>size>>k;
    vector<int> arr;

    for(int i =0; i<size; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i =0; i<k; i++){
        int x;
        cin>>x;
        closestToLeft(arr, x);
    }


}