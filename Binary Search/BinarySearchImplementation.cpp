#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int key, int size){

    int s = 0, e = size-1;

    while(s <= e){
        int mid = s + (e-s)/2;

        if(arr[mid] > key)
            e = mid-1;

        else if(arr[mid] < key)
            s = mid+1;

        else
            return mid;
    }

    return -1;
}

int main(){

    int size, key;
    cin>>size>>key;

    int* arr = new int[size];

    for(int i=0; i<size; i++)
        cin>>arr[i];

    cout<<search(arr, key, size);
}