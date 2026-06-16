#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>>& maze){

    int n=maze.size();

    if(row<0 || col<0 || row>=n || col>=n)
        return false; // outside maze

    if(maze[row][col]==0)
        return false; // blocked cell or already visited

    return true;
}

void findPaths(int row,int col,
               vector<vector<int>>& maze,
               string& currentPath,
               vector<string>& allPaths){

    int n=maze.size();

    if(row==n-1 && col==n-1){
        allPaths.push_back(currentPath); // destination reached
        return;
    }

    maze[row][col]=0; // mark current cell visited to avoid cycles

    if(isSafe(row,col+1,maze)){
        currentPath.push_back('R'); // choose Right
        findPaths(row,col+1,maze,currentPath,allPaths);
        currentPath.pop_back(); // backtrack path string
    }

    if(isSafe(row+1,col,maze)){
        currentPath.push_back('D'); // choose Down
        findPaths(row+1,col,maze,currentPath,allPaths);
        currentPath.pop_back();
    }

    if(isSafe(row-1,col,maze)){
        currentPath.push_back('U'); // choose Up
        findPaths(row-1,col,maze,currentPath,allPaths);
        currentPath.pop_back();
    }

    if(isSafe(row,col-1,maze)){
        currentPath.push_back('L'); // choose Left
        findPaths(row,col-1,maze,currentPath,allPaths);
        currentPath.pop_back();
    }

    maze[row][col]=1; // restore cell for other possible paths
}

vector<string> findPath(vector<vector<int>>& maze){

    vector<string> allPaths;

    if(maze.empty() || maze[0][0]==0)
        return allPaths; // rat cannot start

    string currentPath;

    findPaths(0,0,maze,currentPath,allPaths);

    return allPaths;
}