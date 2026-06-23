#include <iostream>
#include <stack>
using namespace std;

class StockSpanner { //23-06-2026
private:
    int arr[10000];
    int i;
    stack<int> st; //stores indices

public:
    StockSpanner() {
        i = -1;
    }

    int next(int price) {
        arr[++i] = price;

        while(!st.empty() && arr[st.top()] <= price)
            st.pop(); //remove smaller or equal prices

        int span;

        if(st.empty())
            span = i + 1; //no previous greater element
        else
            span = i - st.top(); //distance from previous greater element

        st.push(i);

        return span;
    }
};

int main() {
    StockSpanner spanner;

    int n;

    cout << "Enter number of stock prices: ";
    cin >> n;

    cout << "Enter stock prices:\n";

    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;

        cout << spanner.next(price) << " ";
    }

    return 0;
}