// KAHN'S ALGORITHM

#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<int> adjList[], vector<int> &inDegree){

    queue<int> q;
    int cnt = 0;
    for(int i = 0; i<inDegree.size(); i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){

        int tmp = q.front();
        q.pop();
        cnt++;

        for(auto it: adjList[tmp]){
            inDegree[it]--;
            if(inDegree[it] <= 0){
                q.push(it);
            }        
        }
    }
    if(cnt != inDegree.size())
        cout<<"Cyclic\n";
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