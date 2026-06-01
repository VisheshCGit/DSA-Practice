#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n){
    int duprow=row, dupcol=col;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q')
            return false;
        row--;
        col--;
    }

    row=duprow;
    col=dupcol-1;

    while(col>=0){
        if(board[row][col]=='Q')
            return false;
        col--;
    }

    row=duprow+1;
    col=dupcol-1;

    while(row<n && col>=0){
        if(board[row][col]=='Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';

            solve(col+1, ans, board, n);

            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;

    string s(n,'.');
    vector<string> board(n,s);

    solve(0, ans, board, n);

    return ans;
}

int main(){
    int n;

    cout<<"Please enter value of n: ";
    cin>>n;

    vector<vector<string>> result=solveNQueens(n);

    cout<<"Total solutions found: "<<result.size()<<"\n\n";

    for(int i=0;i<result.size();i++){
        cout<<"Solution "<<i+1<<":\n";

        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\n";
        }

        cout<<"\n";
    }

    return 0;
}