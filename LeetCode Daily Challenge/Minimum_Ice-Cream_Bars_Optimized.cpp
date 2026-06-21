#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxIceCream(vector<int>& costs,int coins){

        int maxValue=0;

        for(int i=0;i<costs.size();i++) //find maximum cost
            maxValue=max(maxValue,costs[i]);

        vector<int> freq(maxValue+1,0);

        for(int i=0;i<costs.size();i++) //store frequency of each cost
            freq[costs[i]]++;

        int answer=0;

        for(int cost=1;cost<=maxValue && coins>0;cost++){

            if(freq[cost]==0) continue;

            int purchasable=min(coins/cost,freq[cost]); //maximum ice creams of this cost we can buy

            answer+=purchasable;
            coins-=purchasable*cost;
        }

        return answer;
    }
};

int main(){

    int n,coins;

    cout<<"Enter number of ice creams: ";
    cin>>n;

    vector<int> costs(n);

    cout<<"Enter costs: ";
    for(int i=0;i<n;i++)
        cin>>costs[i];

    cout<<"Enter coins: ";
    cin>>coins;

    Solution obj;

    cout<<"Maximum Ice Creams = "<<obj.maxIceCream(costs,coins);

    return 0;
}