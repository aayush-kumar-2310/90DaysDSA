#include<bits/stdc++.h>
using namespace std;

bool isDirectedCycle(int node, vector<int> adjList[], vector<int> &visited, vector<int> &dfsVisited){

    visited[node] = 1;
    dfsVisited[node] = 1;
    for(auto it: adjList[node]){

        if(!visited[it]){
            if(isDirectedCycle(it, adjList, visited, dfsVisited))
                return true;
        }
        else if(dfsVisited[it])
            return true;
    }

    dfsVisited[node] = 0;
    return false;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], visited(nodes+1, 0), dfsVisited(nodes+1, 0);

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
    }

    for(int i = 1; i<=nodes; i++){
        if(!visited[i]){
            if(isDirectedCycle(i, adjList, visited, dfsVisited)){
                cout<<"Cycle exists.";
                return true;
            }
                
        }
    }
    cout<<"Cycle doesn't exist.";
    return false;
}