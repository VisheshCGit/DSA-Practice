#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) { //22-06-2026
    unordered_map<char, int> mp; //stores frequency of every task

    for(auto &x : tasks)
        mp[x]++;

    int maxFreq = 0; //highest frequency among all tasks

    for(auto &x : mp)
        maxFreq = max(maxFreq, x.second); //A___A___A A has max frequency of 3 and n=3 so 3 _ and all other tasks will be placed in that gap... total block = maxfreq-1 and each block has size n+1 because n is the cooldown time and i space is taken by A itself.. at last we have to add that remaining A for which we have done Maxfreq-1.. so +1.. if there are more characters with max freq then add +countMax

    int countMax = 0; //number of tasks having maximum frequency

    for(auto &x : mp) {
        if(x.second == maxFreq)
            countMax++;
    }

    return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + countMax);
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

    cout << "Minimum time required: " << leastInterval(tasks, n);

    return 0;
}