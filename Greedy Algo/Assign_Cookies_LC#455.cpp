#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0;
    int cookie = 0;
    int contentChildren = 0;

    while(child < g.size() && cookie < s.size()) {
        if(s[cookie] < g[child]) {
            cookie++;
        }
        else {
            contentChildren++;
            child++;
            cookie++;
        }
    }

    return contentChildren;
}

int main() {
    int n, m;

    cout << "Please enter number of children: ";
    cin >> n;

    vector<int> greed(n);

    cout << "Please enter greed factors: ";
    for(int i = 0; i < n; i++)
        cin >> greed[i];

    cout << "Please enter number of cookies: ";
    cin >> m;

    vector<int> cookies(m);

    cout << "Please enter cookie sizes: ";
    for(int i = 0; i < m; i++)
        cin >> cookies[i];

    cout << "Maximum Content Children: "
         << findContentChildren(greed, cookies)
         << endl;

    return 0;
}