#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void calcTime(int node, vector<int> adjList[], vector<int> &visited, vector<int> &inTimer, vector<int> &outTimer){

    visited[node] = 1;
    inTimer[node] = ++timer;

    for(auto it: adjList[node]){
        if(!visited[it])
            calcTime(it, adjList, visited, inTimer, outTimer);
    }

    outTimer[node] = ++timer;
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], visited(nodes+1, 0), inTimer(nodes+1, 0), outTimer(nodes+1, 0);
    
    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

            calcTime(1, adjList, visited, inTimer, outTimer); // 1 is the root of the tree.

    for(auto x: inTimer)
        cout<<x<<" ";
    cout<<endl;

    for(auto x: outTimer)
        cout<<x<<" ";
}