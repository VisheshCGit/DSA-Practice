#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    // DFS to visit the complete island
    void dfs(vector<vector<char>> &grid, int row, int col){

        // Out of boundary or already visited
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size())
            return;

        if(grid[row][col]=='0')
            return;

        // Mark current land as visited by converting it into water
        grid[row][col]='0';

        // Visit all four neighbouring cells
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }

    int numIslands(vector<vector<char>> &grid){

        int rows=grid.size();
        int cols=grid[0].size();

        int islands=0;

        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){

                // New island found
                if(grid[i][j]=='1'){

                    islands++;

                    dfs(grid,i,j);
                }
            }
        }

        return islands;
    }
};