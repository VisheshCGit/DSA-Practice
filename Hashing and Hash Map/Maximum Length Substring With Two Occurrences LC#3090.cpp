#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int maximumLengthSubstring(string s){
        unordered_map<char,int> mp;
        int left=0,ans=0;

        for(int right=0;right<s.size();right++){
            mp[s[right]]++;

            while(mp[s[right]]>2)
                mp[s[left++]]--;

            ans=max(ans,right-left+1);
        }

        return ans;
    }
};

int main(){
    string s;

    cout<<"Enter string: ";
    cin>>s;

    Solution obj;

    cout<<"Maximum Length = "<<obj.maximumLengthSubstring(s);

    return 0;
}