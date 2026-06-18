#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:  //18-June-2026
    double angleClock(int hour, int minutes) {

        // Convert hour hand position into equivalent minute marks.
        double hourPosition = (hour * 5) % 60;

        // Every minute moves the hour hand by 1/12 of a minute mark.
        hourPosition += (1.0 / 12.0) * minutes;

        // Difference between hour hand and minute hand.
        double difference = abs(hourPosition - minutes);

        // Take the smaller circular distance.
        difference = min(difference, 60.0 - difference);

        // Each minute mark corresponds to 6 degrees.
        return difference * 6.0;
    }
};

int main() {

    int hour, minutes;

    cout << "Enter hour and minutes: ";
    cin >> hour >> minutes;

    Solution obj;

    cout << "Angle between clock hands = "
         << obj.angleClock(hour, minutes)
         << " degrees" << endl;

    return 0;
}