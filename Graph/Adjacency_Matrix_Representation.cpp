#include<bits/stdc++.h>
using namespace std;

int main(){

    int nodes, edges;
    cin>>nodes>>edges;

    int adjMatrix[nodes+1][nodes+1] = {};

    for(int i=0; i<edges; i++){
        int a, b;
        cin>>a>>b;
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }

    for(int i = 0; i<nodes+1; i++){
        for(int j = 0; j<nodes+1; j++)
            cout<<adjMatrix[i][j]<<" ";
        cout<<endl;
    }
}