#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> adjList[], vector<int> &visited, stack<int> &elements){

    visited[node] = 1;

    for(auto it: adjList[node]){
        if(!visited[it]){
            topoSort(it, adjList, visited, elements);
        }
    }
    elements.push(node);
}   

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], visited(nodes+1, 0);
    stack<int> elements;

    for(int i = 0; i<edges; i++){
        int a, b; cin>>a>>b;

        adjList[a].push_back(b);
    }

    for(int i = 0; i<nodes; i++){
        if(!visited[i])
            topoSort(i, adjList, visited, elements);
    }

    while(!elements.empty()){
        cout<<elements.top()<<" ";
        elements.pop();
    }
}