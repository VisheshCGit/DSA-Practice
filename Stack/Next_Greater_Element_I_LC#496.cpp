#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std; //23-06-2026

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> mp; //stores next greater element for every value

    stack<int> st; //monotonically decreasing stack

    for(int i = nums2.size() - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= nums2[i])
            st.pop(); //remove useless smaller elements

        if(st.empty())
            mp[nums2[i]] = -1;
        else
            mp[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    vector<int> ans;

    for(int i = 0; i < nums1.size(); i++)
        ans.push_back(mp[nums1[i]]);

    return ans;
}

int main() {

    int n, m;

    cout << "Enter size of nums1: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter elements of nums1:\n";
    for(int i = 0; i < n; i++)
        cin >> nums1[i];

    cout << "Enter size of nums2: ";
    cin >> m;

    vector<int> nums2(m);

    cout << "Enter elements of nums2:\n";
    for(int i = 0; i < m; i++)
        cin >> nums2[i];

    vector<int> ans = nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements:\n";

    for(auto x : ans)
        cout << x << " ";

    return 0;
}