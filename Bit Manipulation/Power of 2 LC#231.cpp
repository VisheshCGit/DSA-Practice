#include <iostream>
using namespace std;

class Solution{
public:

    // Check whether the given number is a power of 2
    bool isPowerOfTwo(int n){

        // Powers of 2 are always positive
        if(n<=0)
            return false;

        // Power of 2 has exactly one set bit
        return (n & (n-1))==0;
    }
};

int main(){

    Solution obj;

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(obj.isPowerOfTwo(n))
        cout<<"Power of 2";
    else
        cout<<"Not a Power of 2";

    return 0;
}