#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s){
        int i=s.size()-1,ans=0;

        while(i>=0 && s[i]==' ')
            i--;

        while(i>=0 && s[i]!=' '){
            ans++;
            i--;
        }

        return ans;
    }
};

int main(){

    string s;

    cout<<"Enter the string: ";
    getline(cin,s);

    Solution obj;

    cout<<"Length of Last Word = "<<obj.lengthOfLastWord(s);

    return 0;
}