#include <iostream>
#include <string>
using namespace std;

string removeStars(string s){
    string ans;

    for(auto &x:s){
        if(x=='*')
            ans.pop_back(); //remove previous character
        else
            ans.push_back(x); //use string as stack
    }

    return ans;
}

int main(){
    string s;

    cout<<"Enter string: ";
    cin>>s;

    cout<<"Answer: "<<removeStars(s);

    return 0;
}