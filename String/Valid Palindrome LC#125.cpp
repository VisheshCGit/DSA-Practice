#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        string palin="";

        for(char x:s){
            if(isalpha(x) || isdigit(x)){
                if(isalpha(x) && x>='A' && x<='Z')
                    palin.push_back(x+32);
                else
                    palin.push_back(x);
            }
        }

        int i=0,j=palin.size()-1;

        while(i<j){
            if(palin[i]!=palin[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};

int main(){

    string s;

    cout<<"Enter the string: ";
    getline(cin,s);

    Solution obj;

    if(obj.isPalindrome(s))
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";

    return 0;
}