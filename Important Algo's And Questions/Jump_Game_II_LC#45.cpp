#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int jumps = 0;          // Number of jumps taken so far
        int currentEnd = 0;     // End of the range reachable using current number of jumps
        int farthest = 0;       // Farthest index we can reach while scanning the current range

        // We don't need to process the last index because once we reach it,
        // no further jump is required from there.
        for (int i = 0; i < n - 1; i++) {

            // While scanning the current range, keep track of the farthest
            // position that can be reached using one more jump.
            farthest = max(farthest, i + nums[i]);

            // If we have reached the end of the current jump range,
            // it means we have explored all positions reachable using
            // the current number of jumps.
            if (i == currentEnd) {

                // Therefore, taking one more jump becomes mandatory.
                jumps++;

                // The next jump range now extends up to the farthest
                // position we discovered while scanning the previous range.
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

int main() {

    int n;

    cout << "Please enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Minimum jumps required = "
         << obj.jump(nums) << endl;

    return 0;
}