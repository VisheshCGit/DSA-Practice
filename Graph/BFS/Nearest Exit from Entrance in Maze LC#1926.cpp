#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBoundary(int row, int col, vector<vector<char>> &maze){
    return row==0 || col==0 || row==maze.size()-1 || col==maze[0].size()-1;
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance){
    int m=maze.size(), n=maze[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n,false));
    queue<pair<int,int>> q;

    visited[entrance[0]][entrance[1]]=true;    // Mark source visited before pushing
    q.push({entrance[0],entrance[1]});

    pair<int,int> source={entrance[0],entrance[1]};

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};

    int steps=0;

    while(!q.empty()){
        int levelSize=q.size();    // Current BFS level

        while(levelSize--){
            auto curr=q.front();
            q.pop();

            int row=curr.first;
            int col=curr.second;

            if(isBoundary(row,col,maze) && curr!=source)
                return steps;

            for(int i=0;i<4;i++){
                int newRow=row+dr[i];
                int newCol=col+dc[i];

                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n &&
                   !visited[newRow][newCol] && maze[newRow][newCol]!='+'){
                    visited[newRow][newCol]=true;    // Prevent duplicate insertion
                    q.push({newRow,newCol});
                }
            }
        }

        steps++;    // Move to the next distance level
    }

    return -1;
}

int main(){
    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<char>> maze(m, vector<char>(n));

    cout<<"Enter maze:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>maze[i][j];

    vector<int> entrance(2);

    cout<<"Enter entrance row and column: ";
    cin>>entrance[0]>>entrance[1];

    cout<<"Nearest Exit = "<<nearestExit(maze,entrance);

    return 0;
}