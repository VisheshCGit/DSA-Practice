#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int dfs(vector<vector<int>> &triangle,int row,int col,vector<vector<int>> &dp){

    if(row==triangle.size()-1)
        return triangle[row][col]; //last row reached

    if(dp[row][col]!=INT_MAX)
        return dp[row][col]; //already calculated

    int down=dfs(triangle,row+1,col,dp); //move down
    int diagonal=dfs(triangle,row+1,col+1,dp); //move diagonally

    return dp[row][col]=triangle[row][col]+min(down,diagonal);
}

int minimumTotal(vector<vector<int>> &triangle){

    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

    return dfs(triangle,0,0,dp);
}

int main(){

    int n;

    cout<<"Enter number of rows : ";
    cin>>n;

    vector<vector<int>> triangle(n);

    cout<<"Enter triangle elements :\n";

    for(int i=0;i<n;i++){
        triangle[i].resize(i+1);

        for(int j=0;j<=i;j++)
            cin>>triangle[i][j];
    }

    cout<<"Minimum Path Sum : "<<minimumTotal(triangle);

    return 0;
}