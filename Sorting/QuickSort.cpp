#include<bits/stdc++.h>
using namespace std;

int Partition(vector<int> &v, int s, int e){

    int pivot = v[e];
    int i = s-1;

    for(int j=s; j<e; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[e]);
    return i+1;
}

void QuickSort(vector<int> &v, int s, int e){

    if(s >= e)
        return;

    int pivot = Partition(v, s, e);
    QuickSort(v, s, pivot-1);
    QuickSort(v, pivot+1, e);
}

int main(){

    int size; 
    cin>>size;

    vector<int> v;

    for(int i=0; i<size; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<"Before Sort: ";
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;

    QuickSort(v, 0, v.size()-1);
    
    cout<<"After Sort: ";
    for(auto x:v)
        cout<<x<<" ";
}