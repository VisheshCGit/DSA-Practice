#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    bool isPossible(int day,vector<int> &bloomDay,int m,int k){
        int bouquet=0,flower=0;

        for(int x:bloomDay){
            if(x<=day){
                flower++;

                if(flower==k){
                    bouquet++;
                    flower=0;

                    if(bouquet==m)
                        return true;
                }
            }
            else
                flower=0;
        }

        return false;
    }

    int minDays(vector<int> &bloomDay,int m,int k){
        if(1LL*m*k>bloomDay.size())
            return -1;

        int low=INT_MAX,high=INT_MIN;

        for(int x:bloomDay){
            low=min(low,x);
            high=max(high,x);
        }

        while(low<high){
            int mid=low+(high-low)/2;

            if(isPossible(mid,bloomDay,m,k))
                high=mid;
            else
                low=mid+1;
        }

        return low;
    }
};

int main(){

    int n,m,k;

    cout<<"Enter number of flowers: ";
    cin>>n;

    vector<int> bloomDay(n);

    cout<<"Enter bloom days: ";
    for(int &x:bloomDay)
        cin>>x;

    cout<<"Enter number of bouquets: ";
    cin>>m;

    cout<<"Enter flowers per bouquet: ";
    cin>>k;

    Solution obj;

    cout<<"Minimum Days = "<<obj.minDays(bloomDay,m,k);

    return 0;
} 