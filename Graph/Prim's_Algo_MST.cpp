#include<bits/stdc++.h>
using namespace std;

int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<pair<int, int>> adjList[nodes];
    vector<int> key(nodes, INT_MAX), parents(nodes, -1);
    vector<bool> inMST(nodes, false);

    for(int i = 0; i<edges; i++){
        int a, b, wt; cin>>a>>b>>wt;

        adjList[a].push_back({b, wt});
        adjList[b].push_back({a, wt});
    }

    key[0] = 0;

    for(int count = 0;  count < nodes-1; count++){

        int miniWt = INT_MAX, miniNode;

        for(int i=0; i<nodes; i++)
            if(key[i] < miniWt and inMST[i] == false)
                miniWt = key[i], miniNode = i;

        inMST[miniNode] = true;

        for(auto it: adjList[miniNode]){
            if(it.second < key[it.first] and inMST[it.first] ==  false)
                key[it.first] = it.second, parents[it.first] = miniNode;
        }
    }

    for(auto x: parents)
        cout<<x<<" ";

}