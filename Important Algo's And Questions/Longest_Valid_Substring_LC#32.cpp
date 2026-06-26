#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s){
    stack<int> st;
    st.push(-1); //initial boundary before the string starts

    int ans=0;

    for(int i=0; i<s.size(); i++){

        if(s[i]=='('){
            st.push(i); //store index of every opening bracket
        }

        else{
            if(!st.empty()) //we are updating boundary if ')' has no match so that index becomes our boundary 
                st.pop(); //match current ')' with previous boundary/opening bracket

            if(st.empty()){
                st.push(i); //current ')' becomes the new invalid boundary
            }

            else{
                ans=max(ans,i-st.top()); //current valid substring starts after the top boundary
            }
        }
    }

    return ans;
}

int main(){
    string s;

    cout<<"Enter parentheses string: ";
    cin>>s;

    cout<<"Longest Valid Parentheses Length: "<<longestValidParentheses(s);

    return 0;
}