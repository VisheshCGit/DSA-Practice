#include <iostream>
using namespace std;

class Solution{
public:
    bool checkDivisibility(int n){
        int sum=0,product=1;
        int x=n;

        while(n>0){
            int rem=n%10;
            sum+=rem;
            product*=rem;
            n/=10;
        }

        sum+=product;

        return x%sum==0;
    }
};

int main(){
    int n;

    cout<<"Enter number: ";
    cin>>n;

    Solution obj;

    if(obj.checkDivisibility(n))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}