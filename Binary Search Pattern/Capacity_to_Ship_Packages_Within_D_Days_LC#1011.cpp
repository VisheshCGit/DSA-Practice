#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& weights, int capacity, int days) {
    int count = 1;
    int sum = 0;

    for(int i = 0; i < weights.size(); i++) {
        if(sum + weights[i] > capacity) {
            count++;
            sum = weights[i];
        }
        else {
            sum += weights[i];
        }
    }

    return count <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();

    int low = 0;
    int high = 0;

    for(int i = 0; i < n; i++) {
        low = max(low, weights[i]);
        high += weights[i];
    }

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(check(weights, mid, days))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n, days;

    cout << "Please enter number of packages: ";
    cin >> n;

    vector<int> weights(n);

    cout << "Please enter package weights: ";
    for(int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Please enter number of days: ";
    cin >> days;

    int ans = shipWithinDays(weights, days);

    cout << "Minimum ship capacity required: " << ans << endl;

    return 0;
}