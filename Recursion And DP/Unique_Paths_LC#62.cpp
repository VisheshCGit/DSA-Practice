#include<iostream>
#include<vector>
using namespace std;

int path(int i, int j, vector<vector<int>> &dp) {

    if(i == 0 && j == 0)
        return 1;

    if(i < 0 || j < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = path(i - 1, j, dp);
    int left = path(i, j - 1, dp);

    dp[i][j] = up + left;

    return dp[i][j];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return path(m - 1, n - 1, dp);
}

int main() {
    int m, n;

    cout << "Please enter number of rows: ";
    cin >> m;

    cout << "Please enter number of columns: ";
    cin >> n;

    int totalPaths = uniquePaths(m, n);

    cout << "Total unique paths: " << totalPaths << endl;

    return 0;
}