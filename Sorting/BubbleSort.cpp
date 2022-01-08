#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int size){

    bool swapped = false;
    for(int i=0; i<=size-1; i++){

        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }        
        }

        if(swapped == false)
            break;
    }    
}

int main(){

    int size;
    cin>>size;

    int* arr = new int[size];
    for(int i=0; i<size; i++)   
        cin>>arr[i];

    BubbleSort(arr, size);

    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
}