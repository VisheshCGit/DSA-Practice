#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    string convert(string s,int numRows){
        int n=s.size();

        if(numRows==1 || n<=numRows)
            return s;

        vector<string> rows(numRows);
        int curr=0;
        bool forward=true;

        for(char x:s){
            rows[curr].push_back(x);

            if(curr==numRows-1)
                forward=false;
            else if(curr==0)
                forward=true;

            if(forward)
                curr++;
            else
                curr--;
        }

        string ans="";

        for(string &row:rows)
            ans+=row;

        return ans;
    }
};

int main(){

    string s;
    int numRows;

    cout<<"Enter string: ";
    getline(cin,s);

    cout<<"Enter number of rows: ";
    cin>>numRows;

    Solution obj;

    cout<<"Converted String = "<<obj.convert(s,numRows);

    return 0;
}