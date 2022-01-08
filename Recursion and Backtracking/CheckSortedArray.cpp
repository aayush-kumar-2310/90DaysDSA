#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size, int i){

    if(i+1 == size)
        return true;

    return arr[i] < arr[i+1] && isSorted(arr, size, ++i); 
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};

    cout<<isSorted(arr, sizeof(arr)/sizeof(int), 0);
}