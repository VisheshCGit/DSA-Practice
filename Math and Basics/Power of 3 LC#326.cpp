#include <iostream>
using namespace std;

class Solution{
public:

    // Check whether the given number is a power of 3
    bool isPowerOfThree(int n){

        // Powers of 3 are always positive
        if(n<=0)
            return false;

        // Keep dividing by 3 while possible
        while(n%3==0)
            n/=3;

        // If we finally reach 1, it was a power of 3
        return n==1;
    }
};

int main(){

    Solution obj;

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(obj.isPowerOfThree(n))
        cout<<"Power of 3";
    else
        cout<<"Not a Power of 3";

    return 0;
}