#include<bits/stdc++.h>
using namespace std;

int calcSize(int node, vector<int> adjList[], vector<int> &visited, vector<int> &subTreeSize){

    visited[node] = 1;
    int size = 1;

    for(auto it: adjList[node]){
        if(!visited[it]){
            size += calcSize(it, adjList, visited, subTreeSize);
        }
    }
    subTreeSize[node] = size;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], visited(nodes+1, 0), subTreeSize(nodes+1, 0);

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    calcSize(1, adjList, visited, subTreeSize);

    for(auto x:subTreeSize)
        cout<<x<<" ";
}