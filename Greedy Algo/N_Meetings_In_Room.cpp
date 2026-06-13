#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct Data {
        int start;
        int end;
        int pos;
    };

    static bool cmp(const Data& a, const Data& b) {
        if (a.end == b.end)
            return a.start < b.start;

        return a.end < b.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        if (n == 0)
            return 0;

        vector<Data> meetings(n);

        for (int i = 0; i < n; i++) {
            meetings[i].start = start[i];
            meetings[i].end = end[i];
            meetings[i].pos = i;
        }

        sort(meetings.begin(), meetings.end(), cmp); // sorting by ending time.. 

        int meetingsCount = 1;
        int freeTime = meetings[0].end;

        for (int i = 1; i < n; i++) {
            if (meetings[i].start > freeTime) {
                meetingsCount++;
                freeTime = meetings[i].end;
            }
        }

        return meetingsCount;
    }
};

int main() {
    int n;

    cout << "Please enter number of meetings: ";
    cin >> n;

    vector<int> start(n);
    vector<int> end(n);

    cout << "Please enter start times: ";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Please enter end times: ";
    for (int i = 0; i < n; i++)
        cin >> end[i];

    Solution obj;

    cout << "Maximum meetings possible: "
         << obj.maxMeetings(start, end)
         << endl;

    return 0;
}