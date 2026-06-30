#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    int numberOfSubstrings(string s){

        unordered_map<char,int> freq;

        freq['a']=0;
        freq['b']=0;
        freq['c']=0;

        int left=0;
        int answer=0;

        for(int right=0;right<s.size();right++){

            freq[s[right]]++; //include current character in window

            while(freq['a']>0 && freq['b']>0 && freq['c']>0){ //current window contains all three characters

                answer+=s.size()-right; //all larger windows will also be valid

                freq[s[left]]--; //shrink window from left
                left++;
            }
        }

        return answer;
    }
};

int main(){

    string s;

    cout<<"Enter string: ";
    cin>>s;

    Solution obj;

    cout<<"Number of Substrings = "<<obj.numberOfSubstrings(s);

    return 0;
}