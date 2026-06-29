#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string reverseWords(string s){

        string answer;

        while(s.back()==' ') //remove trailing spaces
            s.pop_back();

        int lastSpace=s.size();

        for(int i=s.size()-1;i>=0;i--){

            if(s[i]==' '){

                if(i<s.size()-1 && s[i+1]!=' '){ //ignore consecutive spaces

                    answer.append(s.substr(i+1,lastSpace-i-1)); //append current word
                    answer+=" ";
                }

                lastSpace=i; //mark end of next word
            }

            if(i==0 && s[i]!=' '){ //append first word
                answer.append(s.substr(i,lastSpace));
                answer+=" ";
            }
        }

        answer.pop_back(); //remove extra space at end

        return answer;
    }
};

int main(){

    string s;

    cout<<"Enter string: ";
    getline(cin,s);

    Solution obj;

    cout<<"Reversed String = "<<obj.reverseWords(s);

    return 0;
}