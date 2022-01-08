#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void calcBridge(int node, int parent, vector<int> adjList[], vector<int> &vis, vector<int> &lt, vector<int> &inTime){

    vis[node] = 1;
    inTime[node] = lt[node] = ++timer;

    for(auto it: adjList[node]){

        if(it == parent) continue;

        if(!vis[it]){
            calcBridge(it, node, adjList, vis, lt, inTime);
            
            lt[node] = min(lt[node], lt[it]);

            if(lt[it] > inTime[node])
                cout<<"Bridge b/w "<<it<<" and "<<node<<endl;
            
        }

        else{
            lt[node] = min(inTime[it], lt[node]);
            //cout<<"Child: "<<it<<" Parent: "<<node<<endl; 
        }
    }
        
}

 
int main(){

    int nodes, edges; cin>>nodes>>edges;

    vector<int> adjList[nodes+1], inTime(nodes), lowTime(nodes), visited(nodes, 0);

    for(int i = 0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    calcBridge(1, -1, adjList, visited, lowTime, inTime);
}