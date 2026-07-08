#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:

    bool inRange(int row, int col, vector<vector<int>> &grid){
        return row>=0 && row<grid.size() &&
               col>=0 && col<grid[0].size();
    }

    int orangesRotting(vector<vector<int>> &grid){

        queue<pair<int,int>> q;

        int freshCount=0;

        // Store all initially rotten oranges
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]==2)
                    q.push({i,j});

                else if(grid[i][j]==1)
                    freshCount++;
            }
        }

        if(freshCount==0)
            return 0;

        int minutes=0;

        while(!q.empty()){

            int size=q.size();

            while(size--){

                auto curr=q.front();
                q.pop();

                int row=curr.first;
                int col=curr.second;

                // Down
                if(inRange(row+1,col,grid) && grid[row+1][col]==1){
                    grid[row+1][col]=2;
                    freshCount--;
                    q.push({row+1,col});
                }

                // Up
                if(inRange(row-1,col,grid) && grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    freshCount--;
                    q.push({row-1,col});
                }

                // Right
                if(inRange(row,col+1,grid) && grid[row][col+1]==1){
                    grid[row][col+1]=2;
                    freshCount--;
                    q.push({row,col+1});
                }

                // Left
                if(inRange(row,col-1,grid) && grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    freshCount--;
                    q.push({row,col-1});
                }
            }

            // If new rotten oranges are available,
            // next BFS level represents next minute.
            if(!q.empty())
                minutes++;
        }

        if(freshCount>0)
            return -1;

        return minutes;
    }
};

int main(){

    vector<vector<int>> grid={
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution obj;

    cout<<"Minimum Minutes = "<<obj.orangesRotting(grid);

    return 0;
}