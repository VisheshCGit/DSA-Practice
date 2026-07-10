#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid){
    int n=grid.size();

    if(grid[0][0]==1 || grid[n-1][n-1]==1)    // Path can't start or end on a blocked cell
        return -1;

    vector<vector<bool>> visited(n, vector<bool>(n,false));
    queue<pair<int,int>> q;

    q.emplace(0,0);
    visited[0][0]=true;

    int pathLength=1;

    int dr[]={-1,1,0,0,-1,-1,1,1};
    int dc[]={0,0,-1,1,-1,1,-1,1};

    while(!q.empty()){
        int levelSize=q.size();    // Nodes at current distance

        while(levelSize--){
            auto curr=q.front();
            q.pop();

            int row=curr.first;
            int col=curr.second;

            if(row==n-1 && col==n-1)
                return pathLength;

            for(int i=0;i<8;i++){
                int newRow=row+dr[i];
                int newCol=col+dc[i];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<n &&
                   !visited[newRow][newCol] && grid[newRow][newCol]==0){
                    visited[newRow][newCol]=true;    // Discover cell only once
                    q.emplace(newRow,newCol);
                }
            }
        }

        if(!q.empty())
            pathLength++;
    }

    return -1;
}

int main(){
    int n;

    cout<<"Enter grid size: ";
    cin>>n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout<<"Enter grid:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    cout<<"Shortest Path Length = "<<shortestPathBinaryMatrix(grid);

    return 0;
}