#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int leastInterval(vector<char>& tasks, int n) { //22-06-2026
    unordered_map<char, int> mp;

    for(auto &x : tasks)
        mp[x]++;

    priority_queue<int> pq; //stores frequencies of available tasks

    for(auto &x : mp)
        pq.push(x.second);

    queue<pair<int, int>> q; //{remaining frequency, next available time}

    int time = 0;

    while(!pq.empty() || !q.empty()) {

        time++;

        if(!pq.empty()) {
            int freq = pq.top();
            pq.pop();

            freq--; //execute current task

            if(freq > 0)
                q.push({freq, time + n}); //put task into cooldown
        }

        while(!q.empty() && q.front().second <= time) {
            pq.push(q.front().first); //cooldown finished
            q.pop();
        }
    }

    return time;
}

int main() {

    int m, n;

    cout << "Enter number of tasks: ";
    cin >> m;

    vector<char> tasks(m);

    cout << "Enter tasks:\n";
    for(int i = 0; i < m; i++)
        cin >> tasks[i];

    cout << "Enter cooldown time: ";
    cin >> n;

    cout << "Minimum time required: "
         << leastInterval(tasks, n);

    return 0;
}