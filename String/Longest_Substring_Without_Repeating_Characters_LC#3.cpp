#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s){
    if(s.size()<=1)
        return s.size();

    int longest=1;
    int left=0;

    unordered_map<char,int> lastIndex;

    for(int right=0;right<s.size();right++){

        if(lastIndex.find(s[right])!=lastIndex.end())
            left=max(left,lastIndex[s[right]]+1);

        lastIndex[s[right]]=right;

        longest=max(longest,right-left+1);
    }

    return longest;
}

int main(){
    string s;

    cout<<"Please enter the string: ";
    cin>>s;

    cout<<"Length of longest substring without repeating characters: "
        <<lengthOfLongestSubstring(s);

    return 0;
}