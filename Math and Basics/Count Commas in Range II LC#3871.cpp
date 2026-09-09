#include <iostream>
using namespace std;

class Solution{
public:
    long long countCommas(long long n){
        long long ans=0;
        long long value=1000;
        long long counter=1;

        while(value<=n){
            long long next=value*1000;

            if(next<=n)
                ans+=counter*(next-value);
            else
                ans+=counter*(n-value+1);

            value=next;
            counter++;
        }

        return ans;
    }
};

int main(){
    long long n;

    cout<<"Enter n: ";
    cin>>n;

    Solution obj;

    cout<<"Total commas = "<<obj.countCommas(n);

    return 0;
}