#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int v){
    
    for(int i =0; i < v; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void fillArray(int arr[], int ind, int v){

    if(ind == v){
        print(arr, ind);
        return;
    }

    arr[ind] = ind+1;
    
    fillArray(arr, ind+1, v);
    arr[ind] = -arr[ind];
}

int main(){
    int arr[100];
    fillArray(arr, 0, 5);
    print(arr, 5);
}