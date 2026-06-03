#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    int i = 0;
    int j = 1;

    // Transpose the matrix
    for (int a = 1; a <= (n * (n - 1) / 2); a++) {

        swap(matrix[i][j], matrix[j][i]);

        if (j < n - 1) {
            j++;
        }
        else {
            i++;
            j = i + 1;
        }
    }

    // Reverse each row
    i = 0;
    j = n - 1;

    while (j >= i) {

        for (int x = 0; x < n; x++) {
            swap(matrix[x][i], matrix[x][j]);
        }

        i++;
        j--;
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    cout << "\nRotated Matrix:\n";

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {

    int n;

    cout << "Please enter matrix size (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Please enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix);

    printMatrix(matrix);

    return 0;
}