#include<bits/stdc++.h>
using namespace std;

void calcPath(int node, vector<int> adjList[], vector<int> &visited, vector<int> &distance){

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
                if(distance[tmp] + 1 < distance[it]) distance[it] = distance[tmp] + 1;
                q.push(it);
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

    int query; cin>>query;

    for(int i=0; i<query; i++){
        int x, y, cnt = 0; cin>>x>>y;
        calcPath(x, adjList, visited, distance);
        for(auto it: distance)
            if(it == y)
                cnt++;
        cout<<cnt<<endl;

        fill(visited.begin(), visited.end(), 0);            // FILLS BOTH THE VECTORS WITH 0's 
        fill(distance.begin(), distance.end(), INT_MAX);    // TO RUN ANOTHER QUERY
    }
}