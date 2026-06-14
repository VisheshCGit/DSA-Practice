#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arrival,
                     vector<int>& departure) {

        int n = arrival.size();

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int arrivalPointer = 0;     //we are sorting according to the time.. i will keep track of arrival of trains and j will keep track of departure time..
        int departurePointer = 0;  // if a train leaves the platform then that platform becomes free so count--;  

        int currentPlatforms = 0;
        int maximumPlatforms = 0;

        while (arrivalPointer < n) {

            if (arrival[arrivalPointer] <= departure[departurePointer]) {
                currentPlatforms++;
                arrivalPointer++;
            }
            else {
                currentPlatforms--;
                departurePointer++;
            }

            maximumPlatforms =
                max(maximumPlatforms, currentPlatforms); // we are calculating the maximum platforms occupied at a time that will be the answer
        }

        return maximumPlatforms;
    }
};

int main() {
    int n;

    cout << "Please enter number of trains: ";
    cin >> n;

    vector<int> arrival(n);
    vector<int> departure(n);

    cout << "Please enter arrival times: ";
    for (int i = 0; i < n; i++)
        cin >> arrival[i];

    cout << "Please enter departure times: ";
    for (int i = 0; i < n; i++)
        cin >> departure[i];

    Solution obj;

    cout << "Minimum platforms required: "
         << obj.findPlatform(arrival, departure)
         << endl;

    return 0;
}