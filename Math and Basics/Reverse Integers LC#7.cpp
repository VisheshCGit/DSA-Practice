#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution{
public:

    // Reverses the digits of an integer.
    // Returns 0 if the reversed number overflows.
    int reverse(int x){

        int sign=1;

        if(x<0)
            sign=-1;

        // Convert to positive using long long to safely handle INT_MIN
        long long num=x;

        if(num<0)
            num=-num;

        string digits=to_string(num);

        string reversed="";

        while(!digits.empty()){
            reversed.push_back(digits.back());
            digits.pop_back();
        }

        long long ans=0;

        for(char digit:reversed)
            ans=ans*10+(digit-'0');

        ans*=sign;

        if(ans>INT_MAX || ans<INT_MIN)
            return 0;

        return ans;
    }
};

int main(){

    Solution obj;

    int x;

    cout<<"Enter a number: ";
    cin>>x;

    cout<<"Reversed Number = "<<obj.reverse(x);

    return 0;
}