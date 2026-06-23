#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st; //{value, minimum till this position}

public:
    void push(int value) {
        if(st.empty())
            st.push({value, value}); //first element becomes minimum itself
        else
            st.push({value, min(value, st.top().second)}); //store current minimum
    }

    void pop() {
        if(!st.empty())
            st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

    bool isEmpty() {
        return st.empty();
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(2);
    st.push(7);
    st.push(1);

    cout << "Current Top: " << st.top() << endl;
    cout << "Current Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top After Pop: " << st.top() << endl;
    cout << "Minimum After Pop: " << st.getMin() << endl;

    return 0;
}