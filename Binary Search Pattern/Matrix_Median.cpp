#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // Returns true if there are at least medianPosition
    // elements less than or equal to candidateValue.
    bool check(vector<vector<int>>& matrix, int candidateValue, int medianPosition) {

        int count = 0;

        for (int row = 0; row < matrix.size(); row++) {

            int low = 0;
            int high = matrix[0].size() - 1;

            // Stores the last index whose value <= candidateValue
            int lastValidIndex = -1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (matrix[row][mid] <= candidateValue) {

                    // Current element can contribute to count
                    lastValidIndex = mid;

                    // Try finding a larger valid index
                    low = mid + 1;
                }
                else {

                    high = mid - 1;
                }
            }

            // Number of elements <= candidateValue in this row
            count += (lastValidIndex + 1);
        }

        return count >= medianPosition;
    }

    int findMedian(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Minimum possible median value
        int low = INT_MAX;

        // Maximum possible median value
        int high = INT_MIN;

        // Since every row is sorted,
        // first element of row can contribute to global minimum
        // and last element of row can contribute to global maximum.
        for (int row = 0; row < rows; row++) {

            low = min(low, matrix[row][0]);
            high = max(high, matrix[row][cols - 1]);
        }

        // Position of median in sorted order (1-based)
        int medianPosition = (rows * cols + 1) / 2;

        // First True Binary Search
        while (low < high) {

            int mid = low + (high - low) / 2;

            if (check(matrix, mid, medianPosition)) {

                // Enough elements are <= mid
                // Try finding a smaller valid median
                high = mid;
            }
            else {

                // Too few elements <= mid
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements row-wise:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;

    cout << "Median = " << obj.findMedian(matrix) << endl;

    return 0;
}