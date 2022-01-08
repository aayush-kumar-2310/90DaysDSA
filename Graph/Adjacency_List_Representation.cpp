#include<bits/stdc++.h>
using namespace std;

int main(){

    int nodes, edges;
    cin>>nodes>>edges;

    vector<int> adjList[nodes+1];

    for(int i = 0; i<edges; i++){
        int a, b;
        cin>>a>>b;
        
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    cout<<"Adjacency List :\n";

    for(int i =0; i<nodes+1; i++){
        cout<<i<<" ";
        for(auto x: adjList[i])
            cout<<x<<" ";
        cout<<endl;
    }
}