#include <iostream>
using namespace std;

class Solution{
public:
    int countCommas(int n){
        if(n>999)
            return n-999;

        return 0;
    }
};

int main(){
    int n;

    cout<<"Enter n: ";
    cin>>n;

    Solution obj;

    cout<<"Count of Commas = "<<obj.countCommas(n);

    return 0;
}