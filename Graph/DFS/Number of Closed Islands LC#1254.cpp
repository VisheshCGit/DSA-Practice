#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    vector<int> dr={-1,1,0,0};
    vector<int> dc={0,0,-1,1};

    // DFS to explore the complete island
    void dfs(vector<vector<int>> &grid,
             int row,
             int col,
             bool &isClosed){

        if(row<0 || col<0 ||
           row>=grid.size() ||
           col>=grid[0].size() ||
           grid[row][col]==1)
            return;

        // Island touches boundary
        if(row==0 || col==0 ||
           row==grid.size()-1 ||
           col==grid[0].size()-1)

            isClosed=false;

        // Mark current land as visited
        grid[row][col]=1;

        // Visit all four neighbours
        for(int i=0;i<4;i++)
            dfs(grid,row+dr[i],col+dc[i],isClosed);
    }

    int closedIsland(vector<vector<int>> &grid){

        int closedIslands=0;

        for(int i=0;i<grid.size();i++){

            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]==0){

                    bool isClosed=true;

                    dfs(grid,i,j,isClosed);

                    if(isClosed)
                        closedIslands++;
                }
            }
        }

        return closedIslands;
    }
};