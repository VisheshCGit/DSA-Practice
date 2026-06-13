#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n <= 1)
            return 0;

        sort(intervals.begin(), intervals.end(), cmp);  // custom comparator is being used to sort according to the second element or end... then compare with next intervals if they overlap or not

        int nonOverlappingCount = 1;
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                nonOverlappingCount++;
                lastEndTime = intervals[i][1];
            }
        }

        return n - nonOverlappingCount;
    }
};

int main() {
    int n;

    cout << "Please enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Please enter start and end times:\n";

    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution obj;

    cout << "Minimum intervals to remove: "
         << obj.eraseOverlapIntervals(intervals)
         << endl;

    return 0;
}