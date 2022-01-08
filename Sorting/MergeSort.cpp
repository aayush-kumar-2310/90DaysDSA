#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &v, int s, int e){
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    vector<int> tempSort;

    while(i<=m and j<=e){
        if(v[i] < v[j]){
            tempSort.push_back(v[i]);
            i++;
        }
        else{
            tempSort.push_back(v[j]);
            j++;
        }
        
    }

    while(i<=m){
        tempSort.push_back(v[i]);
        i++;
    }

    while(j<=e){
        tempSort.push_back(v[j]);
        j++;
    }

    int k =0;
    for(int ind = s; ind<=e; ind++){
        v[ind] = tempSort[k++];
    }
    return;
}

void MergeSort(vector<int> &v, int s, int e){

    if(s>=e)
        return;

    int m = (s+e)/2;

    MergeSort(v,s,m);
    MergeSort(v,m+1,e);

    return Merge(v,s,e);
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

    MergeSort(v,0, v.size());

    for(auto x:v)
        cout<<x<<" ";
}