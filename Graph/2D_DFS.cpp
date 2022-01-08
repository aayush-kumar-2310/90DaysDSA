#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001]={};
bool vis[1001][1001]={};

int dx[] = {0, -1, 0, 1};       // RIGHT UP LEFT DOWN
int dy[] = {1, 0, -1, 0};       // RIGHT UP LEFT DOWN

bool isValid(int x, int y, int n){

    if(x>=n or x<0 or y>=n or y<0 or vis[x][y] or arr[x][y] == 0)
        return false;

    return true;
} 



void dfsGrid(int x, int y, int size){

    vis[x][y] = 1;

    //cout<<x<<" "<<y<<endl;     //TRAVERSAL

    for(int i =0; i<4; i++){
        if(isValid(x+dx[i], y+dy[i], size))
            dfsGrid(x+dx[i], y+dy[i], size);
    }
}

int main(){

    int n, cc = 0; cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 and !vis[i][j]){
                cc++;
                dfsGrid(i, j, n);
            }
        }
    }
    cout<<cc;
}
