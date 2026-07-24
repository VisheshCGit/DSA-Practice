#include <iostream>
using namespace std;

class Solution{
public:

    // Counts the number of set bits (1s) in the binary representation
    int hammingWeight(int n){

        int count=0;

        while(n){
            n=n&(n-1);   // Removes the rightmost set bit
            count++;
        }

        return count;
    }
};

int main(){

    Solution obj;

    int n;

    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Number of Set Bits = "<<obj.hammingWeight(n);

    return 0;
}