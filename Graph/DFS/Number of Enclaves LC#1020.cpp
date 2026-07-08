#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    vector<int> dr={-1,1,0,0};
    vector<int> dc={0,0,-1,1};

    bool isBoundary(vector<vector<int>> &grid,int row,int col){

        return row==0 || col==0 || row==grid.size()-1 || col==grid[0].size()-1;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int &componentSize, bool &touchesBoundary){                 
         if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0)
            return;

        grid[row][col]=0;

        componentSize++;

        if(isBoundary(grid,row,col))
            touchesBoundary=true;

        for(int i=0;i<4;i++)
            dfs(grid,row+dr[i],col+dc[i],componentSize,touchesBoundary);
    }

    int numEnclaves(vector<vector<int>> &grid){

        int total=0;

        for(int i=0;i<grid.size();i++){

            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]==1){

                    int componentSize=0;

                    bool touchesBoundary=false;

                    dfs(grid,i,j,componentSize,touchesBoundary);

                    if(!touchesBoundary)
                        total+=componentSize;
                }
            }
        }

        return total;
    }
};