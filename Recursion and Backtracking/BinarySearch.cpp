#include<bits/stdc++.h>
using namespace std;

int search(int arr[] ,int key ,int start,int end) {

    if(start > end)
        return -1;

    int mid = start + (end - start)/2;

    if( arr[mid] == key) 
        return mid;

    if(key > arr[mid]) 
        return search(arr, key, mid+1, end);

    if(key < arr[mid]) 
        return search(arr, key, start, mid-1);
}

int main() {


    cout<<"Enter size of array";
    int key, size;
    cin>>size;
    int* arr = new int[size];

    cout<<"Enter numbers in SORTED FORM ONLY:";
    for(int i=0; i<size; i++)
        cin>>arr[i];

    cin>>key;
    cout<<search(arr, key, 0, 5);

}