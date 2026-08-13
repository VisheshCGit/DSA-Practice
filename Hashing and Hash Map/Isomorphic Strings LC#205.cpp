#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s,string t){
        if(s.size()!=t.size())
            return false;

        unordered_map<char,char> mp;
        unordered_set<char> st;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                if(st.find(t[i])!=st.end())
                    return false;

                mp[s[i]]=t[i];
                st.insert(t[i]);
            }
            else{
                if(mp[s[i]]!=t[i])
                    return false;
            }
        }

        return true;
    }
};

int main(){
    string s,t;

    cout<<"Enter first string: ";
    cin>>s;

    cout<<"Enter second string: ";
    cin>>t;

    Solution obj;

    if(obj.isIsomorphic(s,t))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}