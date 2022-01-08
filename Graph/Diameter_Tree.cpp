#include<bits/stdc++.h>
using namespace std;

int distMax = 0;
int distNode;
void dfs(int node, vector<int> adjList[], vector<int> visited, vector<int> &distance){

    visited[node] = 1;

    for(auto it: adjList[node]){
        if(!visited[it]){
            distance[it] = 1 + distance[node];
            if(distance[it] > distMax){
                distMax = distance[it];
                distNode = it;
            }
            dfs(it, adjList, visited, distance);
        }
    }
}

int main(){

    int nodes; cin>>nodes;
    vector<int> adjList[nodes+1], visited(nodes+1, 0), distance(nodes+1, 0);

    for(int i = 1; i<=nodes-1; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    distance[1] = 0;
    
    dfs(1, adjList, visited, distance);
    fill(visited.begin(), visited.end(), 0);
    fill(distance.begin(), distance.end(), 0);
    distMax = 0;
    dfs(distNode, adjList, visited, distance);

    cout<<distMax;
}