// KAHN'S ALGORITHM

#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<int> adjList[], vector<int> &inDegree){

    queue<int> q;

    for(int i = 0; i<inDegree.size(); i++){
        if(inDegree[i] == 0){
            cout<<i<<" ";
            q.push(i);
        }
    }
    
    while(!q.empty()){

        int tmp = q.front();
        q.pop();

        for(auto it: adjList[tmp]){
            inDegree[it]--;
            if(inDegree[it] <= 0){
                q.push(it);
                cout<<it<<" ";
            }
                
        }
    }
}

int main(){

    int nodes, edges; cin>>nodes>>edges;
    vector<int> adjList[nodes], inDegree(nodes, 0);

    for(int i=0; i<edges; i++){
        int a,b; cin>>a>>b;

        adjList[a].push_back(b);
        inDegree[b]++;
    }

    topoSort(adjList, inDegree);

}