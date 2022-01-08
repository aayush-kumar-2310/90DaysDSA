#include<bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int> &visited, vector<int> &dfsTraversal, vector<int> adj[]){
        
    visited[n] = 1;
    dfsTraversal.push_back(n);
    
    for(auto it: adj[n]){
        if(!visited[it])
            dfs(it, visited, dfsTraversal, adj);
    }
}
    
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
    vector<int> dfsTraversal, visited(V+1, 0);
    
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            dfs(i, visited, dfsTraversal, adj);
        }
    }
    
    return dfsTraversal;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> visited(nodes+1, 0), dfsTraversal, adjList[nodes+1];

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for(int i = 0; i<edges; i++){
        if(!visited[i])
            dfs(i, visited, dfsTraversal, adjList);
    }

    for(auto it: dfsTraversal)
        cout<<it<<" ";
}
