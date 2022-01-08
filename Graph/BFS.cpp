#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
    vector<int> bfsTraversal, visited(V, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
        
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfsTraversal.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }   
    }
    return bfsTraversal;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes];

    for(int i = 0; i<edges; i++){
        int a, b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<int> dfsTraversal = bfsOfGraph(nodes, adjList);
}