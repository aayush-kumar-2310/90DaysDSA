#include<bits/stdc++.h>
using namespace std;

void CyclicSort(int arr[], int size){

        int i = 0;
        
        while( i < size){
            if(i+1 != arr[i])
                swap(arr[i], arr[arr[i]-1]);

            else
                i++;
        }
}

int main(){

    int size;
    cin>>size;

    int* arr = new int[size];
    
    for(int i=0; i<size; i++)
        cin>>arr[i];

    CyclicSort(arr, size);

    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
}