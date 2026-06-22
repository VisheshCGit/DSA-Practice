#include <iostream>
#include <vector>
#include <queue>
using namespace std; //22-06-2026

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    priority_queue<pair<long long, pair<int, int>>> maxHeap;

    for(auto &point : points) { //& is used to avoid copying of vector everytime

        long long x = point[0];
        long long y = point[1];

        long long distance = x * x + y * y;

        maxHeap.push({distance, {point[0], point[1]}});

        if(maxHeap.size() > k)
            maxHeap.pop();
    }

    vector<vector<int>> ans;

    while(!maxHeap.empty()) {

        auto curr = maxHeap.top();
        maxHeap.pop();

        int x = curr.second.first;
        int y = curr.second.second;

        ans.push_back({x, y});
    }

    return ans;
}

int main() {

    int n, k;

    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter x and y coordinates:\n";

    for(int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];

    cout << "Enter k: ";
    cin >> k;

    vector<vector<int>> ans = kClosest(points, k);

    cout << "K Closest Points:\n";

    for(auto &point : ans)
        cout << "[" << point[0] << ", " << point[1] << "]\n";

    return 0;
}