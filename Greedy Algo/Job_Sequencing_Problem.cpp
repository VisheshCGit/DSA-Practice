#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct Job {
        int id;
        int deadline;
        int profit;
    };

    static bool cmp(const Job& a, const Job& b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(vector<vector<int>>& jobs) {
        int n = jobs.size();

        vector<Job> allJobs(n);

        for (int i = 0; i < n; i++) {
            allJobs[i].id = jobs[i][0];
            allJobs[i].deadline = jobs[i][1];
            allJobs[i].profit = jobs[i][2];
        }

        sort(allJobs.begin(), allJobs.end(), cmp);

        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, allJobs[i].deadline);
        }

        vector<int> slot(maxDeadline + 1, -1);
    // Sort the job by max profit and perform that job on the last day of the deadline.. so that remaining slots can be used in future
        int totalJobs = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {

            int currentDeadline = allJobs[i].deadline;

            while (currentDeadline > 0 &&
                   slot[currentDeadline] != -1) {
                currentDeadline--;
            }

            if (currentDeadline > 0) {
                slot[currentDeadline] = allJobs[i].id;

                totalJobs++;
                totalProfit += allJobs[i].profit;
            }
        }

        return {totalJobs, totalProfit};
    }
};

int main() {
    int n;

    cout << "Please enter number of jobs: ";
    cin >> n;

    vector<vector<int>> jobs(n, vector<int>(3));

    cout << "Please enter jobId deadline profit:\n";

    for (int i = 0; i < n; i++) {
        cin >> jobs[i][0]
            >> jobs[i][1]
            >> jobs[i][2];
    }

    Solution obj;

    vector<int> answer =
        obj.JobScheduling(jobs);

    cout << "Jobs Scheduled: "
         << answer[0] << endl;

    cout << "Maximum Profit: "
         << answer[1] << endl;

    return 0;
}