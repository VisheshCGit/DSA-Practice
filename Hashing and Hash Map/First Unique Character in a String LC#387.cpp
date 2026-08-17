#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int firstUniqChar(string s){
        unordered_map<char,int> mp;

        for(char x:s)
            mp[x]++;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1)
                return i;
        }

        return -1;
    }
};

int main(){
    string s;

    cout<<"Enter string: ";
    cin>>s;

    Solution obj;

    cout<<"First Unique Character Index = "<<obj.firstUniqChar(s);

    return 0;
}