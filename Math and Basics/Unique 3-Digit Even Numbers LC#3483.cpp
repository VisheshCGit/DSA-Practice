#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int totalNumbers(vector<int> &digits){
        vector<int> freq(10,0);

        for(auto x:digits)
            freq[x]++;

        int ans=0;

        for(int i=1;i<=9;i++){
            if(freq[i]==0)
                continue;

            freq[i]--;

            for(int j=0;j<=9;j++){
                if(freq[j]==0)
                    continue;

                freq[j]--;

                for(int k=0;k<=8;k+=2){
                    if(freq[k]>0)
                        ans++;
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return ans;
    }
};

int main(){
    int n;

    cout<<"Enter number of digits: ";
    cin>>n;

    vector<int> digits(n);

    cout<<"Enter digits: ";
    for(int &x:digits)
        cin>>x;

    Solution obj;

    cout<<"Total distinct three-digit even numbers = "
        <<obj.totalNumbers(digits);

    return 0;
}