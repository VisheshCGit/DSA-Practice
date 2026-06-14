#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGain = 0;      // Net fuel available in the entire circle
        int currentTank = 0;   // Fuel remaining while testing current start station
        int startStation = 0;  // Current candidate answer

        for (int i = 0; i < gas.size(); i++) {

            int gain = gas[i] - cost[i];

            totalGain += gain;
            currentTank += gain;

            // If tank becomes negative, we cannot reach the next station.
            if (currentTank < 0) {

                // Any station between startStation and i
                // is guaranteed to be invalid.
                startStation = i + 1;

                // Start fresh from the next station.
                currentTank = 0;
            }
        }

        // If total fuel is less than total cost,
        // completing the circuit is impossible.
        if (totalGain < 0)
            return -1;

        return startStation;
    }
};

int main() {

    int n;

    cout << "Please enter number of stations: ";
    cin >> n;

    vector<int> gas(n);
    vector<int> cost(n);

    cout << "Please enter gas values:\n";
    for (int i = 0; i < n; i++)
        cin >> gas[i];

    cout << "Please enter cost values:\n";
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    Solution obj;

    cout << "Starting Station = "
         << obj.canCompleteCircuit(gas, cost)
         << endl;

    return 0;
}