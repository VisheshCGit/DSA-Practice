#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s){
    stack<int> st;
    int number=0;
    char op='+';

    for(int i=0;i<s.size();i++){

        if(isdigit(s[i]))
            number=number*10+(s[i]-'0');

        if((!isdigit(s[i]) && s[i]!=' ') || i==s.size()-1){

            if(op=='+')
                st.push(number);

            else if(op=='-')
                st.push(-number);

            else if(op=='*'){
                int top=st.top();
                st.pop();
                st.push(top*number);
            }

            else{
                int top=st.top();
                st.pop();
                st.push(top/number);
            }

            op=s[i];
            number=0;
        }
    }

    int ans=0;

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main(){

    string s;

    cout<<"Enter expression: ";
    getline(cin,s);

    cout<<"Answer: "<<calculate(s);

    return 0;
}