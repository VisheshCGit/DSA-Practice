#include <iostream>
#include <unordered_set>
using namespace std;

class Solution{
public:
    bool isHappy(int n){
        unordered_set<int> st;

        st.insert(n);

        while(n!=1){

            int sum=0;

            while(n){
                int rem=n%10;
                sum+=rem*rem;
                n/=10;
            }

            if(st.find(sum)!=st.end())
                return false;

            st.insert(sum);
            n=sum;
        }

        return true;
    }
};

int main(){

    int n;

    cout<<"Enter a number: ";
    cin>>n;

    Solution obj;

    if(obj.isHappy(n))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}