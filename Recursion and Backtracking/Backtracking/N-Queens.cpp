#include<bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){


    if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i<n; i++){
            if(leftRow[i] == 0 and lowerDiagonal[i+col] == 0 and upperDiagonal[n-1 + col-i]==0){
                board[i][col] = 'Q';
                leftRow[i] = 1;
                lowerDiagonal[i+col] = 1;
                upperDiagonal[n-1+col-i] = 1;
            
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[i][col] = '.';
                leftRow[i] = 0;
                lowerDiagonal[i+col] = 0;
                upperDiagonal[n-1+col-i] = 0;

            }
        }
}

int main(){

    int n;
    cin>>n;

    vector<vector<string>> ans;
    vector<string> board (n);
    string s(n, '.');

    for(int i = 0; i<n; i++)
        board[i] = s;


    vector<int> leftRow(n,0), upperDiag(2*n -1, 0), lowerDiag(2*n -1, 0);
    solve(0, board, ans, leftRow, upperDiag, lowerDiag, n)

}