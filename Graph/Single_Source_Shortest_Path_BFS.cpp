#include<bits/stdc++.h>
using namespace std;

void calcPathSize(int node, vector<int> adjList[], vector<int> &visited, vector<int> &distance){

    visited[node] = 1;
    distance[node] = 0;
    queue<int> q;
    q.push(node);

    while(!q.empty()){

        int tmp = q.front();
        q.pop();

        for(auto it: adjList[tmp]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
                if(distance[tmp] + 1 < distance[it])
                    distance[it] = distance[tmp] + 1;
            }
        }
    }
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], visited(nodes+1, 0), distance(nodes+1, INT_MAX);

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    calcPathSize(3, adjList, visited, distance);

    for(auto x: distance)
        cout<<x<<" ";

}