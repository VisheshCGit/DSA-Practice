#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n,
           vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){

    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 &&
           lowerDiagonal[row+col]==0 &&
           upperDiagonal[n-1+col-row]==0){

            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;

            board[row][col]='Q';

            solve(col+1, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);

            board[row][col]='.';

            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;

    string s(n,'.');
    vector<string> board(n,s);

    vector<int> leftRow(n,0);
    vector<int> upperDiagonal(2*n-1,0);
    vector<int> lowerDiagonal(2*n-1,0);

    solve(0, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);

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