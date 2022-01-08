#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visisted, vector<int> adjList[]){

    visisted[node] = 1;

    for(auto it: adjList[node]){
        if(!visisted[it])
            dfs(it, visisted, adjList);
    }
}

int main(){

    int nodes, edges, cnt = 0; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], visited(nodes+1, 0);

    for(int i = 1; i<=edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for(int i = 1; i<nodes; i++){
        if(!visited[i]){
            cnt++;
            dfs(i, visited, adjList);
        }
    }

    if(cnt == 1 and nodes-1 == edges)
        cout<<"YES";
    else
        cout<<"NO";
}