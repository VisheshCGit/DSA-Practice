#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) { //23-06-2026
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {

        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]); //push opening brackets

        else {

            if(st.empty())
                return false; //closing bracket without opening bracket

            if(st.top() == '(' && s[i] != ')')
                return false;

            if(st.top() == '{' && s[i] != '}')
                return false;

            if(st.top() == '[' && s[i] != ']')
                return false;

            st.pop(); //matching pair found
        }
    }

    if(!st.empty())
        return false; //some opening brackets left unmatched

    return true;
}

int main() {

    string s;

    cout << "Enter expression: ";
    cin >> s;

    if(isValid(s))
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";

    return 0;
}