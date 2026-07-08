#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    vector<int> dr={-1,1,0,0};
    vector<int> dc={0,0,-1,1};

    // Mark all boundary connected 'O'
    void dfs(vector<vector<char>> &board,int row,int col){

        if(row<0 || col<0 ||
           row>=board.size() ||
           col>=board[0].size() ||
           board[row][col]=='X' ||
           board[row][col]=='@')
            return;

        board[row][col]='@';

        for(int i=0;i<4;i++)
            dfs(board,row+dr[i],col+dc[i]);
    }

    void solve(vector<vector<char>> &board){

        int rows=board.size();
        int cols=board[0].size();

        // Start DFS from all boundary cells
        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){

                if((i==0 || j==0 || i==rows-1 || j==cols-1)
                    && board[i][j]=='O')

                    dfs(board,i,j);
            }
        }

        // Capture surrounded regions
        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){

                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='@')
                    board[i][j]='O';
            }
        }
    }
};