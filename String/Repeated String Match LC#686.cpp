#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution{
public:
    int repeatedStringMatch(string a,string b){

        int minimumRepeats=ceil((double)b.size()/a.size());

        string repeatedString="";

        for(int i=0;i<minimumRepeats;i++) //create minimum repeated string
            repeatedString+=a;

        if(repeatedString.find(b)!=string::npos) //check if b is present
            return minimumRepeats;

        repeatedString+=a; //one extra repeat for boundary overlap

        if(repeatedString.find(b)!=string::npos)
            return minimumRepeats+1;

        return -1;
    }
};

int main(){

    string a,b;

    cout<<"Enter first string: ";
    cin>>a;

    cout<<"Enter second string: ";
    cin>>b;

    Solution obj;

    cout<<"Minimum Repetitions = "<<obj.repeatedStringMatch(a,b);

    return 0;
}