#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    int romanToInt(string s){

        unordered_map<char,int> mp;

        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int answer=0;

        for(int i=0;i<s.size();i++){

            answer+=mp[s[i]]; //initially assume every symbol is added

            if(i>0 && mp[s[i]]>mp[s[i-1]]) //previous symbol should have been subtracted instead of added
                answer-=2*mp[s[i-1]]; //convert +previous into -previous
        }

        return answer;
    }
};

int main(){

    string roman;

    cout<<"Enter Roman Numeral: ";
    cin>>roman;

    Solution obj;

    cout<<"Integer Value = "<<obj.romanToInt(roman);

    return 0;
}