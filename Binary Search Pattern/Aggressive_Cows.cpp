#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlaceCows(vector<int>& stalls, int cows, int minDistance) {
        int cowsPlaced = 1;
        int lastPosition = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= minDistance) {
                cowsPlaced++;
                lastPosition = stalls[i];
                if (cowsPlaced >= cows)
                    return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int cows) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls.front();
        int answer = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceCows(stalls, cows, mid)) {
                answer = mid;      // feasible answer
                low = mid + 1;     // try larger distance
            }
            else high = mid - 1;     
        }
        return answer;
    }
};

int main() {
    int n, cows;
    cout << "Enter number of stalls: ";
    cin >> n;
    vector<int> stalls(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    cout << "Enter number of cows: ";
    cin >> cows;
    Solution obj;
    cout << "Maximum minimum distance = "
         << obj.aggressiveCows(stalls, cows)
         << endl;
    return 0;
}