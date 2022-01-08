#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int node, vector<int> adjList[], vector<int> &color){

    queue<int> q;
    color[node] = 1;
    q.push(node);

    while(!q.empty()){

        int tmp = q.front();
        q.pop();

        for(auto it: adjList[tmp]){
            if(color[it] == -1 ){
                if(color[tmp] == 1) color[it] = 0;
                else color[it] = 1;

                q.push(it);
            }

            else if(color[it] == color[tmp])
                return false;
        }
    }
    return true;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], color(nodes+1, -1);

    for(int i = 0; i<edges; i++){
        int a, b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(b);
    }

    //We're working on a single connected component,
    //i.e. graph has to be checked for only 1 node.

    cout<<isBipartite(1, adjList, color);
}