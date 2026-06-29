#include <iostream>
#include <string>
using namespace std;

class Solution{
public:

    string expand(int left,int right,const string &s){

        while(left>=0 && right<s.size() && s[left]==s[right]){ //keep expanding while palindrome exists
            left--;
            right++;
        }

        int length=right-left-1; //left and right moved one step extra

        return s.substr(left+1,length); //actual palindrome starts from left+1
    }

    string longestPalindrome(string s){

        string answer=s.substr(0,1); //every single character is a palindrome
        int longest=1;

        for(int i=0;i<s.size();i++){

            string oddCenter=expand(i,i,s); //odd length palindrome
            string evenCenter="";

            if(i+1<s.size())
                evenCenter=expand(i,i+1,s); //even length palindrome

            if(oddCenter.size()>longest){
                answer=oddCenter;
                longest=oddCenter.size();
            }

            if(evenCenter.size()>longest){
                answer=evenCenter;
                longest=evenCenter.size();
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

    cout<<"Longest Palindrome = "<<obj.longestPalindrome(s);

    return 0;
}