#include <iostream>
using namespace std;

class Solution{
public:

    // Check whether the given number is a power of 4
    bool isPowerOfFour(int n){

        // Powers of 4 are always positive
        if(n<=0)
            return false;

        // Keep dividing by 4 while possible
        while(n%4==0)
            n/=4;

        // If we finally reach 1, it was a power of 4
        return n==1;
    }
};

int main(){

    Solution obj;

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(obj.isPowerOfFour(n))
        cout<<"Power of 4";
    else
        cout<<"Not a Power of 4";

    return 0;
}