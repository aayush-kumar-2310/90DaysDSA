#include<bits/stdc++.h>
using namespace std;

int largestIndex(int arr[], int end){

    int m = INT_MIN;
    for(int i=0; i<=end; i++){
        if(arr[i] > m)
            m = arr[i];
    }
    //cout<<m<<" ";
    return m;
}

void SelectionSort(int arr[], int size){

    for(int i=0; i<size; i++){
        
        int maxIndex = largestIndex(arr, size-1-i);
        swap(arr[size-1-i], arr[maxIndex]);

        for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

        cout<<endl;
    }

    

    
}





int main(){

    int size;
    cin>>size;

    int* arr = new int[size];

    for(int i=0; i<size; i++)
        cin>>arr[i];

    SelectionSort(arr, size);

    // for(int i=0; i<size; i++)
    //     cout<<arr[i]<<" ";

}