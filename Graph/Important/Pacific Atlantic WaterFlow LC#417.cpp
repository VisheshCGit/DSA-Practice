#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    const int dr[4]={-1,1,0,0};
    const int dc[4]={0,0,-1,1};

    // Reverse DFS from an ocean
    void dfs(vector<vector<int>> &heights,
             vector<vector<bool>> &visited,
             int row,
             int col,
             int prevHeight){

        // Out of bounds or already visited
        if(row<0 || col<0 ||
           row>=heights.size() ||
           col>=heights[0].size() ||
           visited[row][col])
            return;

        // Reverse flow is only possible towards equal or higher height
        if(heights[row][col] < prevHeight)
            return;

        visited[row][col]=true;

        // Visit all four neighbours
        for(int i=0;i<4;i++)
            dfs(heights,
                visited,
                row+dr[i],
                col+dc[i],
                heights[row][col]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){

        int rows=heights.size();
        int cols=heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols,false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols,false));

        // Pacific touches top row and left column
        for(int i=0;i<rows;i++)
            dfs(heights,pacific,i,0,heights[i][0]);

        for(int j=0;j<cols;j++)
            dfs(heights,pacific,0,j,heights[0][j]);

        // Atlantic touches bottom row and right column
        for(int i=0;i<rows;i++)
            dfs(heights,atlantic,i,cols-1,heights[i][cols-1]);

        for(int j=0;j<cols;j++)
            dfs(heights,atlantic,rows-1,j,heights[rows-1][j]);

        vector<vector<int>> ans;

        // Cells reachable from both oceans
        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){

                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};