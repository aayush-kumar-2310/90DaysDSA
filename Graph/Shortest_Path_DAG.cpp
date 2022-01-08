#include<bits/stdc++.h>
using namespace std;

void shortestWeightedPath(int node, vector<pair<int, int>> adjList[], vector<int> &distance, stack<int> &st){

    distance[node] = 0;

    while(!st.empty()){

        int tmp = st.top();
        st.pop();

        if(distance[tmp] != INT_MAX){
            for(auto it: adjList[tmp]){
            if(distance[tmp] + it.second < distance[it.first])
                distance[it.first] = distance[tmp] + it.second; 
            }
        }
        
    }
}

void topoSort(int node, vector<pair<int,int>> adjList[], vector<int> &visited, stack<int> &st){

    visited[node] = 1;

    for(auto it: adjList[node]){
        if(!visited[it.first])
            topoSort(it.first, adjList, visited, st);
    }
    st.push(node);
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    stack<int> st;
    vector<pair<int, int>> adjList[nodes];
    vector<int> visited(nodes, 0), distance(nodes, INT_MAX), sortedArr;

    for(int i=0; i<edges; i++){
        int a, b, wt; cin>>a>>b>>wt;

        adjList[a].push_back({b,wt});
    }
    for(int i=0; i<nodes; i++)
        if(!visited[i]){
            topoSort(i, adjList, visited, st);
        }
            
    shortestWeightedPath(0, adjList, distance, st);

    // while(!st.empty()){
    // //    sortedArr.push_back(st.top());
    //     cout<<st.top();
    //     st.pop();
    // }

    for(auto x: distance)
        cout<<x<<" ";
}