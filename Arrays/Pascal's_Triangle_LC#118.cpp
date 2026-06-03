#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for(int i = 1; i <= numRows; i++) {
        vector<int> row(i);

        if(i == 1) {
            row = {1};
        }
        else if(i == 2) {
            row = {1, 1};
        }
        else {
            row[0] = 1;
            row[i - 1] = 1;

            for(int j = 1; j < i - 1; j++) {
                row[j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
        }

        ans.push_back(row);
    }

    return ans;
}

int main() {
    int numRows;

    cout << "Please enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> triangle = generate(numRows);

    for(auto row : triangle) {
        for(auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}