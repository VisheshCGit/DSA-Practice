#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>> &image, int row, int col, int newColor, int originalColor){

        if(row<0 || row>=image.size() ||
           col<0 || col>=image[0].size())
            return;

        if(image[row][col]!=originalColor)
            return;

        // Paint current cell
        image[row][col]=newColor;

        // Visit all 4 neighbours
        dfs(image, row+1, col, newColor, originalColor);
        dfs(image, row-1, col, newColor, originalColor);
        dfs(image, row, col+1, newColor, originalColor);
        dfs(image, row, col-1, newColor, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){

        int originalColor=image[sr][sc];

        // Edge Case
        if(originalColor==color)
            return image;

        dfs(image, sr, sc, color, originalColor);

        return image;
    }
};