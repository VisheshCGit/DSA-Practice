#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum<0 || num*9<sum)
            return "";

        string ans="";

        while(num>0){
            int digit=min(9,sum);
            ans.push_back('0'+digit);
            sum-=digit;
            num--;
        }

        if(sum>0)
            return "";

        return ans;
    }
};

int main(){
    int num,sum;

    cout<<"Enter number of digits: ";
    cin>>num;

    cout<<"Enter sum: ";
    cin>>sum;

    Solution obj;

    cout<<"Maximum Sum of Squares Number = "
        <<obj.maxSumOfSquares(num,sum);

    return 0;
}