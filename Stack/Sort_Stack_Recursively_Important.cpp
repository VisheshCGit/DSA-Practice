#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int value) {
    if(st.empty()) {
        st.push(value); //correct position found
        return;
    }

    if(st.top() <= value) {
        st.push(value); //place current element
        return;
    }

    int topElement = st.top();
    st.pop();

    insertSorted(st, value); //find correct position recursively

    st.push(topElement); //restore removed element
}

void sortStackRec(stack<int> &st) {
    if(st.size() <= 1)
        return; //already sorted

    int topElement = st.top();
    st.pop();

    sortStackRec(st); //sort remaining stack

    insertSorted(st, topElement); //insert current element at correct position
}

int main() {
    stack<int> st;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter stack elements:\n";

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    sortStackRec(st);

    cout << "Sorted stack (Top to Bottom):\n";

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}