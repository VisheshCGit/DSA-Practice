#include <iostream>
using namespace std;

class Solution{
public:
    int getProduct(int num){

        if(num==0)
            return 0;

        int product=1;

        while(num){
            int rem=num%10;
            product*=rem;
            num/=10;
        }

        return product;
    }

    int smallestNumber(int n,int t){

        while(getProduct(n)%t!=0)
            n++;

        return n;
    }
};

int main(){

    int n,t;

    cout<<"Enter n and t: ";
    cin>>n>>t;

    Solution obj;

    cout<<"Answer = "<<obj.smallestNumber(n,t);

    return 0;
}