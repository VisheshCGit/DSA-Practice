#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minAddToMakeValid(string s){
    stack<char> st;
    int extraClosing=0;

    for(char ch : s){
        if(ch=='(')
            st.push(ch); //store every opening bracket

        else{
            if(st.empty())
                extraClosing++; //no opening bracket available, so one '(' must be added
            else
                st.pop(); //match current ')' with nearest '('
        }
    }

    return st.size()+extraClosing; //unmatched '(' + unmatched ')'
}

int main(){
    string s;

    cout<<"Enter parentheses string: ";
    cin>>s;

    cout<<"Minimum Additions Required: "<<minAddToMakeValid(s);

    return 0;
}