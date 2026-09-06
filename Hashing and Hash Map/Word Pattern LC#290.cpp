#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool wordPattern(string pattern,string s){
        unordered_map<char,string> mp;
        unordered_map<string,char> rev;

        int i=0;

        for(auto &x:pattern){
            if(i>=s.size())
                return false;

            while(i<s.size() && s[i]==' ')
                i++;

            if(i>=s.size())
                return false;

            int j=i;

            while(i<s.size() && s[i]!=' ')
                i++;

            string word=s.substr(j,i-j);

            if(mp.find(x)!=mp.end()){
                if(mp[x]!=word)
                    return false;
            }
            else{
                if(rev.find(word)!=rev.end())
                    return false;

                mp[x]=word;
                rev[word]=x;
            }

            while(i<s.size() && s[i]==' ')
                i++;
        }

        return i>=s.size();
    }
};

int main(){
    string pattern,s;

    cout<<"Enter pattern: ";
    cin>>pattern;

    cin.ignore();

    cout<<"Enter string: ";
    getline(cin,s);

    Solution obj;

    cout<<"Result = "<<boolalpha<<obj.wordPattern(pattern,s);

    return 0;
}