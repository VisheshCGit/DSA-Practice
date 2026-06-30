#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){

        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];

        int commonLength=strs[0].size();

        for(int i=1;i<strs.size();i++){

            int matchedCharacters=0;
            int first=0, second=0;

            while(first<strs[0].size() && second<strs[i].size()){ //count matching characters from beginning

                if(strs[0][first]==strs[i][second])
                    matchedCharacters++;
                else
                    break;

                first++;
                second++;
            }

            commonLength=min(commonLength,matchedCharacters); //common prefix cannot be longer than current match
        }

        return strs[0].substr(0,commonLength); //extract common prefix from first string
    }
};

int main(){

    int n;

    cout<<"Enter number of strings: ";
    cin>>n;

    vector<string> strs(n);

    cout<<"Enter strings:\n";

    for(int i=0;i<n;i++)
        cin>>strs[i];

    Solution obj;

    cout<<"Longest Common Prefix = "<<obj.longestCommonPrefix(strs);

    return 0;
}