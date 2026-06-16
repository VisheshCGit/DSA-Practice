#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>>& maze,
            vector<vector<int>>& visited){

    int n=maze.size();

    if(row<0 || col<0 || row>=n || col>=n)
        return false; // out of bounds

    if(maze[row][col]==0)
        return false; // blocked cell

    if(visited[row][col])
        return false; // already visited in current path

    return true;
}

void findPaths(int row,int col,
               vector<vector<int>>& maze,
               vector<vector<int>>& visited,
               string& currentPath,
               vector<string>& answer){

    int n=maze.size();

    if(row==n-1 && col==n-1){
        answer.push_back(currentPath); // one valid path found
        return;
    }

    if(isSafe(row,col+1,maze,visited)){
        currentPath.push_back('R');
        visited[row][col+1]=1;
        findPaths(row,col+1,maze,visited,currentPath,answer);
        visited[row][col+1]=0;
        currentPath.pop_back();
    }

    if(isSafe(row+1,col,maze,visited)){
        currentPath.push_back('D');
        visited[row+1][col]=1;
        findPaths(row+1,col,maze,visited,currentPath,answer);
        visited[row+1][col]=0;
        currentPath.pop_back();
    }

    if(isSafe(row-1,col,maze,visited)){
        currentPath.push_back('U');
        visited[row-1][col]=1;
        findPaths(row-1,col,maze,visited,currentPath,answer);
        visited[row-1][col]=0;
        currentPath.pop_back();
    }

    if(isSafe(row,col-1,maze,visited)){
        currentPath.push_back('L');
        visited[row][col-1]=1;
        findPaths(row,col-1,maze,visited,currentPath,answer);
        visited[row][col-1]=0;
        currentPath.pop_back();
    }
}

vector<string> findPath(vector<vector<int>>& maze){

    int n=maze.size();

    vector<string> answer;

    if(maze[0][0]==0)
        return answer;

    vector<vector<int>> visited(n,vector<int>(n,0));

    visited[0][0]=1; // source already belongs to current path

    string currentPath;

    findPaths(0,0,maze,visited,currentPath,answer);

    return answer;
}