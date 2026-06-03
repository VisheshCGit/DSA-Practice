#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

    int n = arr.size();

    int x = 0;
    int cs = 0;
    int ce = 0;

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++) {

        cs = arr[i][0];
        ce = arr[i][1];

        if (cs <= arr[i - 1][1]) {

            if (ce > arr[i - 1][1]) {

                arr[i][0] = arr[i - 1][0];
                arr[x] = arr[i];
            }
            else {

                arr[i] = arr[i - 1];
                arr[x] = arr[i];
            }
        }
        else {
            arr[++x] = arr[i];
        }
    }

    arr.resize(x + 1);

    return arr;
}

int main() {

    int n;

    cout << "Please enter number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    cout << "Please enter intervals (start end):\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> result = mergeOverlap(arr);

    cout << "\nMerged Intervals:\n";

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}