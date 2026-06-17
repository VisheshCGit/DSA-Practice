#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool canPlaceBalls(vector<int>& positions, int balls, int minDistance) {

        int ballsPlaced = 1;
        int lastPosition = positions[0];

        for (int i = 1; i < positions.size(); i++) {

            if (positions[i] - lastPosition >= minDistance) {

                ballsPlaced++;
                lastPosition = positions[i];

                if (ballsPlaced >= balls)
                    return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& positions, int balls) {

        sort(positions.begin(), positions.end());

        int low = 1;
        int high = positions.back() - positions.front();

        while (low < high) {

            // Upper Mid because we are searching for the LAST feasible answer
            int mid = low + (high - low + 1) / 2; // we are finding last true so +1 is done to avoid infinite loop otherwise feasible answer concept could be used 

            if (canPlaceBalls(positions, balls, mid)) {

                // Distance is feasible.
                // Try to find an even larger minimum distance.
                low = mid;
            }
            else {

                // Distance is too large.
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {

    int n, balls;

    cout << "Enter number of positions: ";
    cin >> n;

    vector<int> positions(n);

    cout << "Enter positions: ";

    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    cout << "Enter number of balls: ";
    cin >> balls;

    Solution obj;

    cout << "Maximum Minimum Distance = "
         << obj.maxDistance(positions, balls)
         << endl;

    return 0;
}