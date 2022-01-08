#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(int arr[], int key, int size, int index){

    if(index == size)
        return false;

    return arr[index] == key || LinearSearch(arr, key, size, ++index);
}

int LinearSearchIndex(int arr[], int key, int size, int index){

    if(index == size)
        return -1;

    if(arr[index] == key)
        return index;

    else
        return LinearSearchIndex(arr, key, size, ++index);
}

vector<int> v;
void LinearSearchAllIndex(int arr[], int key, int size, int index){

    if(index == size)
        return;

    if(arr[index] == key)
        v.push_back(index);

    LinearSearchAllIndex(arr, key, size, ++index);
}

vector<int> LinearSearchArray(int arr[], int key, int size, int index, vector<int> &vec){

    if(index == size)
        return vec;

    if(arr[index] == key)
        vec.push_back(index);

    return LinearSearchArray(arr, key, size, ++index, vec);
}

int main(){

    int arr[] = {1,2,3,4,4,4,7}, key;
    cin>>key;

    vector<int> vec;

    cout<<"Found ? "<<LinearSearch(arr, key, sizeof(arr)/sizeof(int), 0);
    LinearSearchAllIndex(arr, key, sizeof(arr)/sizeof(int), 0);
    
    cout<<"\nIndexes: ";
    for(auto x:v){
        cout<<x<<" ";
    }

    LinearSearchArray(arr, key, sizeof(arr)/sizeof(int), 0, vec);

    cout<<"\n\nVector returned: ";
    for(auto x:vec)
        cout<<x<<" ";
}