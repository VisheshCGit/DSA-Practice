#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) { //23-06-2026

    int n = temperatures.size();

    vector<int> ans(n);

    stack<int> st; //{index} //we need that day which is just greater not the value so we had stored index..

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && temperatures[st.top()]<= temperatures[i])
            st.pop(); //remove temperatures that cannot be the next warmer day

        if(st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top()- i; //distance between current day and next warmer day

        st.push(i);
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> temperatures(n);

    cout << "Enter temperatures:\n";

    for(int i = 0; i < n; i++)
        cin >> temperatures[i];

    vector<int> ans = dailyTemperatures(temperatures);

    cout << "Answer:\n";

    for(auto x : ans)
        cout << x << " ";

    return 0;
}