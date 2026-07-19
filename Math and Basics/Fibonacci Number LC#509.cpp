#include <iostream>
using namespace std;

class Solution{
public:

    // Returns the nth Fibonacci number
    int fib(int n){

        if(n<=1)
            return n;

        int prev2=0;
        int prev1=1;

        // Generate Fibonacci numbers iteratively
        for(int i=2;i<=n;i++){

            int curr=prev1+prev2;

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};

int main(){

    Solution obj;

    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Fibonacci Number = "<<obj.fib(n);

    return 0;
}