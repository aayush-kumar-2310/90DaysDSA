#include<bits/stdc++.h>
using namespace std;

bool isCycle(int node, int parent, vector<int> &visited, vector<int> adjList[]){

    visited[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, parent});

    while(!q.empty()){

        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it: adjList[node]){

            if(!visited[it]){
                visited[it] = 1;
                q.push({it, node});
            }

            else if(visited[it] == 1 and it != par)
                return true;
        }
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
        if(!visited[i]){
            if(isCycle(i, -1, visited, adjList)){
                cout<<"True\n";
                return true;
            }
        }
    }
    cout<<"False";
    return false;
}