#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

string removeDuplicateLetters(string s){
    unordered_map<char,int> freq;
    unordered_set<char> present;
    string st; //Internally Behaving Like Stack DS

    for(char &ch:s)
        freq[ch]++; //store frequency of every character

    for(char &ch:s){
        freq[ch]--; //current occurrence has been processed

        if(present.find(ch)!=present.end())
            continue; //character already exists in answer and It's at its best possible Position 

        while(!st.empty() && st.back()>ch && freq[st.back()]>0){
            present.erase(st.back()); //remove from answer because it can appear later
            st.pop_back();
        }

        st.push_back(ch);
        present.insert(ch);
    }
    return st;
}

int main(){
    string s;

    cout<<"Enter string: ";
    cin>>s;

    cout<<"Answer: "<<removeDuplicateLetters(s);

    return 0;
}