#include<bits/stdc++.h>
using namespace std;

int main(){

    int nodes, edges, source; cin>>nodes>>edges>>source;

    vector<int> distance(nodes, INT_MAX), adjList[nodes];

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    distance[source] = 0;

    queue<int> q;
    q.push(source);
    // int d = 1;

    while(!q.empty()){

        int node = q.front();
        q.pop();
        
        for(auto it: adjList[node]){
            if(distance[node] + 1 < distance[it]){
                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
        // d++;
    }

    for(auto it: distance)
        cout<<it<<" ";
}