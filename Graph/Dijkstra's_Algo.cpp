#include<bits/stdc++.h>
using namespace std;

void shortestPath(int src, vector<pair<int, int>> adjList[], vector<int> &distance){

    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, src});

    while(!q.empty()){

        int tmp = q.top().second;
        int dist = q.top().first;
        q.pop();

        for(auto it: adjList[tmp]){
            if(distance[it.first] > distance[tmp] + it.second){
                distance[it.first] = distance[tmp]+ it.second;
                q.push({it.second, it.first});
            }
        }
    }
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<pair<int, int>> adjList[nodes+1];
    vector<int> distance(nodes+1, INT_MAX);

    for(int i=0; i<edges; i++){
        int a,b, wt; cin>>a>>b>>wt;
        
        adjList[a].push_back({b, wt});
        adjList[b].push_back({a, wt});
    }

    shortestPath(1, adjList, distance);
    for(auto x: distance)
        cout<<x<<" ";

}