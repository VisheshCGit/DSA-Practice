#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string shortestBeautifulSubstring(string s,int k){
        int left=0,count=0;
        string ans="";

        for(int right=0;right<s.size();right++){
            if(s[right]=='1')
                count++;

            while(count>k){
                if(s[left++]=='1')
                    count--;
            }

            if(count==k){
                while(s[left]=='0')
                    left++;

                string curr=s.substr(left,right-left+1);

                if(ans.empty() || curr.size()<ans.size() ||
                   (curr.size()==ans.size() && curr<ans))
                    ans=curr;
            }
        }

        return ans;
    }
};

int main(){
    string s;
    int k;

    cout<<"Enter binary string: ";
    cin>>s;

    cout<<"Enter k: ";
    cin>>k;

    Solution obj;

    cout<<"Shortest Beautiful Substring: "
        <<obj.shortestBeautifulSubstring(s,k);

    return 0;
}