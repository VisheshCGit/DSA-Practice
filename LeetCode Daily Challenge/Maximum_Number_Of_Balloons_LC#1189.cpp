#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{ //22-06-2026
public:
    int maxNumberOfBalloons(string text){

        vector<int> freq(26,0);

        for(char ch:text) //count frequency of each character
            freq[ch-'a']++;

        int b=freq['b'-'a'];
        int a=freq['a'-'a'];
        int l=freq['l'-'a']/2; //balloon needs two l's
        int o=freq['o'-'a']/2; //balloon needs two o's
        int n=freq['n'-'a'];

        return min({b,a,l,o,n}); //minimum available requirement decides answer
    }
};

int main(){

    string text;

    cout<<"Enter string: ";
    cin>>text;

    Solution obj;

    cout<<"Maximum Balloons = "<<obj.maxNumberOfBalloons(text);

    return 0;
}