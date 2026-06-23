#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) { //23-06-2026

    int n = heights.size();

    vector<int> prevSmaller(n);
    vector<int> nextSmaller(n);

    stack<int> st;

    for(int i = 0; i < n; i++) {

        while(!st.empty() && heights[st.top()] >= heights[i])  
            st.pop(); //remove greater or equal bars

        if(st.empty())
            prevSmaller[i] = -1;
        else
            prevSmaller[i] = st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop(); //remove greater or equal bars

        if(st.empty())
            nextSmaller[i] = n;
        else
            nextSmaller[i] = st.top();

        st.push(i);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {

        int width = nextSmaller[i] - prevSmaller[i] - 1; //nse-pse-1 because when we have a range of integers say [x,y] and we have to count total integers between that range including x, y.. we do x-y+1.. if we have to include only 1 ofx or y.. we do x-y.. when we don't have to include x and y, we do x-y-1... same logic
        int area = heights[i] * width; // we can expand a rectangle until we encounter the next smaller and a previous smaller.. and we don't have to include indexes of previous and next smaller so nse-pse-1

        ans = max(ans, area);
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights:\n";

    for(int i = 0; i < n; i++)
        cin >> heights[i];

    cout << "Maximum Rectangle Area: "
         << largestRectangleArea(heights);

    return 0;
}