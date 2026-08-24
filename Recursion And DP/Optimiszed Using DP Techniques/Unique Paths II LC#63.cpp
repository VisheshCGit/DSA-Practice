#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int dfs(vector<vector<int>> &grid,vector<vector<int>> &dp,int r,int c){
        if(r>=grid.size() || c>=grid[0].size() || grid[r][c]==1)
            return 0;

        if(r==grid.size()-1 && c==grid[0].size()-1)
            return 1;

        if(dp[r][c]!=-1)
            return dp[r][c];

        return dp[r][c]=dfs(grid,dp,r+1,c)+dfs(grid,dp,r,c+1);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid){
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return dfs(grid,dp,0,0);
    }
};

int main(){
    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> grid(m,vector<int>(n));

    cout<<"Enter grid:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    Solution obj;

    cout<<"Unique Paths = "<<obj.uniquePathsWithObstacles(grid);

    return 0;
}