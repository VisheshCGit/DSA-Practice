#include <iostream>
using namespace std;

class Solution {
public:

    // Returns:
    //  1 -> mid^n == target
    //  0 -> mid^n < target
    // -1 -> mid^n > target
    int checkPower(int mid, int n, int target) {

        long long value = 1;

        for (int i = 1; i <= n; i++) {

            // Prevent overflow and stop early
            if (value > target / mid)
                return -1;

            value *= mid;
        }

        if (value == target)
            return 1;

        return 0;
    }

    int NthRoot(int N, int M) {

        int low = 1;
        int high = M;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int result = checkPower(mid, N, M);

            if (result == 1) {
                return mid;
            }
            else if (result == 0) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    int N, M;

    cout << "Please enter N and M: ";
    cin >> N >> M;

    Solution obj;

    cout << "Nth Root = "
         << obj.NthRoot(N, M)
         << endl;

    return 0;
}