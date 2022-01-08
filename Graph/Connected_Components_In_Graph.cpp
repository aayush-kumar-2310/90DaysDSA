#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[], int count){

	visited[node] = 1;

	for(auto it: adj[node]){
		if(!visited[it]){
			count++;
			dfs(it, visited, adj, count);
		}
	}
}

int main(){

	int nodes, edges, count = 0; cin>>nodes>>edges;
	vector<int> adjList[nodes+1], visited(nodes+1, 0);

	for(int i = 1; i<=edges; i++){
		int a,b; cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	for(int i = 1; i<=nodes; i++){
		if(!visited[i]){
			count++;
			dfs(i, visited, adjList, count);
		}
	}
	cout<<count;
}