#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) { //19-June-2026

    int currentAltitude = 0;
    int highestAltitude = 0; // starting altitude is 0

    for(int i = 0; i < gain.size(); i++) {

        currentAltitude += gain[i]; // update current altitude
        highestAltitude = max(highestAltitude, currentAltitude); // track maximum altitude
    }

    return highestAltitude;
}

int main() {

    int n;
    cout << "Enter number of gains: ";
    cin >> n;

    vector<int> gain(n);

    cout << "Enter gain values: ";
    for(int i = 0; i < n; i++) {
        cin >> gain[i];
    }

    cout << "Highest Altitude: " << largestAltitude(gain);

    return 0;
}