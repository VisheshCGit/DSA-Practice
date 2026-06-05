#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = m - 1;
    int mid;

    // Find the possible row
    while(low < high) {
        mid = low + (high - low) / 2;

        if(target <= matrix[mid][n - 1])
            high = mid;
        else
            low = mid + 1;
    }

    int row = low;

    // Check if target can exist in this row
    if(target < matrix[row][0] || target > matrix[row][n - 1])
        return false;

    // Binary search inside the row
    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = low + (high - low) / 2;

        if(matrix[row][mid] == target)
            return true;
        else if(matrix[row][mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main() {
    int m, n;

    cout << "Please enter number of rows: ";
    cin >> m;

    cout << "Please enter number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Please enter matrix elements row-wise:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;

    cout << "Please enter target value: ";
    cin >> target;

    if(searchMatrix(matrix, target))
        cout << "Target found in matrix.\n";
    else
        cout << "Target not found in matrix.\n";

    return 0;
}