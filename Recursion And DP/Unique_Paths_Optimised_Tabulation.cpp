#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {

            if(i == 0 && j == 0)
                continue;

            int up = 0;
            int left = 0;

            if(i > 0)
                up = dp[i - 1][j];

            if(j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int main() {

    int m, n;

    cout << "Please enter number of rows: ";
    cin >> m;

    cout << "Please enter number of columns: ";
    cin >> n;

    int answer = uniquePaths(m, n);

    cout << "Total unique paths: " << answer << endl;

    return 0;
}