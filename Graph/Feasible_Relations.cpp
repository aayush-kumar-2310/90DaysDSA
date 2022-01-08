#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, int unEq1, int unEq2, vector<int> adjList[], vector<int> &visited){

    visited[node] = 1;
    bool f1 = false, f2 = false;
    queue<int> q;
    q.push(node);

    while(!q.empty()){

        int tmp = q.front();
        q.pop();

        for(auto it: adjList[tmp]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;

                if(it == unEq1) f1 = true;
                if(it == unEq2) f2 = true;
                if(f1 == true and f2 == true)
                    return false;
            }
        }
    }
    return true;
}

int main(){

    int t; cin>>t;

    while(t--){

        int nodes, edges; cin>>nodes>>edges;

        vector<int> adjList[nodes+1], visited(nodes+1, 0);
        vector<pair<int, int>> unEq;

        for(int i = 0; i<edges; i++){
            int a, b;
            string op;
            cin>>a>>op>>b;
            if(op == "="){
                adjList[a].push_back(b);
                adjList[b].push_back(a);
            }
            else{
                unEq.push_back({a,b});
            }
        }

        bool f = false;
        for(int i=0; i<unEq.size(); i++){
            for(int j = 1; j<=nodes; j++)
                if(!visited[j]){
                    cout<<j<<" "<<unEq[i].first<<" "<<unEq[i].second<<endl;
                    if(!bfs(j, unEq[i].first, unEq[i].second, adjList, visited)){
                    f = true;
                    break;
                }
                }
                
        }

        if(f == false)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}