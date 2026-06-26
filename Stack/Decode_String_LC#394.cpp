#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decodeString(string s){
    string st;

    for(char &x:s){

        if(x!=']'){
            st.push_back(x);
            continue;
        }

        string temp,num,decoded;

        while(st.back()!='['){
            temp.push_back(st.back());
            st.pop_back();
        }

        reverse(temp.begin(),temp.end()); //restore original substring
        st.pop_back(); //remove '['

        while(!st.empty() && isdigit(st.back())){
            num.push_back(st.back());
            st.pop_back();
        }

        reverse(num.begin(),num.end()); //restore original number

        int count=stoi(num);

        while(count--)
            decoded+=temp;

        for(char &ch:decoded)
            st.push_back(ch); //we are maintaining correct order in the stack... everytime..
    }

    return st;
}

int main(){
    string s;

    cout<<"Enter encoded string: ";
    cin>>s;

    cout<<"Decoded String: "<<decodeString(s);

    return 0;
}