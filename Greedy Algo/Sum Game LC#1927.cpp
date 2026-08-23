#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    bool sumGame(string num){
        int leftSum=0,rightSum=0,left=0,right=0;
        int n=num.size();

        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2)
                    left++;
                else
                    right++;
            }
            else{
                if(i<n/2)
                    leftSum+=num[i]-'0';
                else
                    rightSum+=num[i]-'0';
            }
        }

        if((left+right)%2)
            return true;

        if(left==right)
            return leftSum!=rightSum;

        return 2*(leftSum-rightSum)!=9*(right-left);
    }
};

int main(){
    string num;

    cout<<"Enter string: ";
    cin>>num;

    Solution obj;

    if(obj.sumGame(num))
        cout<<"Alice wins";
    else
        cout<<"Bob wins";

    return 0;
}