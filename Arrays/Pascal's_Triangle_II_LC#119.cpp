#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int n) {
    vector<int> ans(n + 1);

    if(n == 0)
        return {1};

    if(n == 1)
        return {1, 1};

    ans[0] = 1;
    ans[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = i; j >= 0; j--) {
            if(j == i || j == 0)
                ans[j] = 1;
            else
                ans[j] = ans[j] + ans[j - 1];
        }
    }

    return ans;
}

int main() {
    int n;

    cout << "Please enter row index: ";
    cin >> n;

    vector<int> ans = getRow(n);

    cout << "Pascal Triangle Row: ";

    for(int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}