#include<bits/stdc++.h>
using namespace std;

bool isCycle(int node, vector<int> &visited, vector<int> adjList[], int parent){

    visited[node] = 1;

    for(auto it: adjList[node]){
        
        if(visited[it] == 0)
            if(isCycle(it, visited, adjList, node))
                return true;      

        else if(it != parent)
            return true;        
    }

    return false;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;
    vector<int> adjList[nodes+1], visited(nodes+1, 0);

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for(int i = 1; i<=nodes; i++){
        if(!visited[i])
            if(isCycle(i, visited, adjList, -1)){
                cout<<"True\n";
                return 0;
            }
    }
    cout<<"False\n";
}