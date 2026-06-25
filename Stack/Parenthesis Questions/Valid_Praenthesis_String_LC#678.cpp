#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkValidString(string s){
    stack<int> open; //stores indices of '('
    stack<int> star; //stores indices of '*'

    for(int i=0; i<s.size(); i++){
        if(s[i]=='(')
            open.push(i); //store opening bracket index

        else if(s[i]=='*')
            star.push(i); //store star index

        else{
            if(!open.empty())
                open.pop(); //prefer matching with real '('

            else if(!star.empty())
                star.pop(); //otherwise use '*' as '('

            else
                return false; //nothing available to match ')'
        }
    }

    while(!open.empty()){
        if(star.empty())
            return false; //no '*' left to act as ')'

        if(star.top()<open.top())
            return false; //'*' appears before '(', so it cannot close it

        open.pop();
        star.pop();
    }

    return true;
}

int main(){
    string s;

    cout<<"Enter string: ";
    cin>>s;

    if(checkValidString(s))
        cout<<"Valid";
    else
        cout<<"Invalid";

    return 0;
}