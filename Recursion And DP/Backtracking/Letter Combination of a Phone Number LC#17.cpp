#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:

    // Generates all possible letter combinations
    void solve(unordered_map<int,string> &mp, vector<string> &ans,
               string &digits, int index, string &current){

        if(index==digits.size()){
            ans.push_back(current);
            return;
        }

        string letters=mp[digits[index]-'0'];

        for(char ch:letters){

            current.push_back(ch);

            solve(mp,ans,digits,index+1,current);

            current.pop_back();   // Backtrack
        }
    }

    vector<string> letterCombinations(string digits){

        if(digits.empty())
            return {};

        unordered_map<int,string> mp;

        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

        vector<string> ans;
        string current="";

        solve(mp,ans,digits,0,current);

        return ans;
    }
};

int main(){

    Solution obj;

    string digits;

    cout<<"Enter digits: ";
    cin>>digits;

    vector<string> ans=obj.letterCombinations(digits);

    cout<<"\nPossible combinations:\n";

    for(string &s:ans)
        cout<<s<<" ";

    return 0;
}