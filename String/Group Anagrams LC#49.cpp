#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        unordered_map<string,vector<string>> mp;

        for(string x:strs){
            string key=x;
            sort(key.begin(),key.end());
            mp[key].push_back(x);
        }

        vector<vector<string>> ans;

        for(auto &it:mp)
            ans.push_back(it.second);

        return ans;
    }
};

int main(){
    int n;

    cout<<"Enter number of strings: ";
    cin>>n;

    vector<string> strs(n);

    cout<<"Enter strings: ";
    for(string &x:strs)
        cin>>x;

    Solution obj;
    vector<vector<string>> ans=obj.groupAnagrams(strs);

    cout<<"Groups:\n";

    for(auto &group:ans){
        for(string &s:group)
            cout<<s<<" ";
        cout<<"\n";
    }

    return 0;
}