#include<bits/stdc++.h>
using namespace std;


bool isBipartite(int node, vector<int> adjList[], vector<int> &color){

    queue<int> q;
    q.push(node);

    while(!q.empty()){

        int tmp = q.front();
        q.pop();

        for(auto it: adjList[tmp]){

            if(color[it] == -1){
                color[it] = 1 - color[tmp];
                q.push(it);
            }

            else if(color[it] == color[tmp])
                return false;
        }
    }
    return true;
}

int main(){

    int t; cin>>t;
    int cnt = 0;
    while(t--){
        
        cnt++;
        bool flag = 0;
        int nodes, edges; cin>>nodes>>edges;
        vector<int> adjList[nodes + 1], color(nodes + 1, -1);

        for(int i = 0; i<edges; i++){
            int a,b; cin>>a>>b;

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        for(int i = 1; i<=nodes; i++){

            if(color[i] == -1){
                color[i] = 1;
                if(!isBipartite(i, adjList, color)){
                    flag = 1;
                    cout<<"Scenario #"<<cnt<<":\nSuspicious bugs found!\n";
                    break;
                }
            }
        }
        if(flag == 0)
            cout<<"Scenario #"<<cnt<<":\nNo suspicious bugs found!\n";
    }
}