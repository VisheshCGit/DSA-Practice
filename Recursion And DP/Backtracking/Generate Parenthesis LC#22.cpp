#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    void generate(vector<string> &ans,string &s,int open,int close,int n){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            generate(ans,s,open+1,close,n);
            s.pop_back();
        }

        if(open>close){
            s.push_back(')');
            generate(ans,s,open,close+1,n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string s="";

        generate(ans,s,0,0,n);

        return ans;
    }
};

int main(){

    int n;

    cout<<"Enter number of pairs: ";
    cin>>n;

    Solution obj;

    vector<string> ans=obj.generateParenthesis(n);

    cout<<"Valid Parentheses:\n";

    for(string &s:ans)
        cout<<s<<"\n";

    return 0;
}