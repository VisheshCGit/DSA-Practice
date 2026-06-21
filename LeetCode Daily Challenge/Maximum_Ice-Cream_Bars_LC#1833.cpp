#include <iostream>
#include <vector>
using namespace std;

class Solution{
public: //21-June-2026
    int maxIceCream(vector<int>& costs, int coins){

        int maxValue=0;

        for(int i=0;i<costs.size();i++) //find maximum cost
            maxValue=max(maxValue,costs[i]);

        vector<int> freq(maxValue+1,0);

        for(int i=0;i<costs.size();i++) //store frequency of each cost
            freq[costs[i]]++;

        int answer=0;
        int cost=0;

        while(coins>0 && cost<=maxValue){

            if(freq[cost]!=0 && cost<=coins){ //buy current cheapest ice cream

                answer++;
                coins-=cost;
                freq[cost]--;
            }
            else
                cost++;
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