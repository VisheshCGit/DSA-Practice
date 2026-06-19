#include <iostream>
using namespace std;

/*
    MountainArray API Non Executable code.. refer to LeetCode #1095

    class MountainArray {
    public:
        int get(int index);
        int length();
    };
*/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int low = 0, high = mountainArr.length() - 1;

        while(low < high) { // find peak element index using LC 162 logic
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if(value > mountainArr.get(mid + 1))
                high = mid;
            else
                low = mid + 1;
        }

        int peakIndex = low;
        int peakValue = mountainArr.get(peakIndex);

        if(target > peakValue) return -1; // target cannot exist if it is greater than peak
        if(target == peakValue) return peakIndex;

        low = 0, high = peakIndex - 1;

        while(low <= high) { // binary search on increasing part
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if(value == target) return mid;
            if(value < target) low = mid + 1;
            else high = mid - 1;
        }

        low = peakIndex + 1;
        high = mountainArr.length() - 1;

        while(low <= high) { // binary search on decreasing part
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if(value == target) return mid;
            if(value < target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};