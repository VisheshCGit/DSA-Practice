#include<iostream>
#include<vector>
using namespace std;

int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){

    if(amount==0)
        return 0; // target formed

    if(amount<0 || i==coins.size())
        return 1e9; // impossible state

    if(dp[i][amount]!=-1)
        return dp[i][amount]; // state already computed

    int take=1+solve(i, coins, amount-coins[i], dp); // reuse same coin

    int notTake=solve(i+1, coins, amount, dp); // move to next coin

    return dp[i][amount]=min(take, notTake);
}

int coinChange(vector<int>& coins, int amount){

    vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

    int answer=solve(0, coins, amount, dp);

    return (answer>=1e9) ? -1 : answer;
}

int main(){

    int n;

    cout<<"Please enter number of coins: ";
    cin>>n;

    vector<int> coins(n);

    cout<<"Please enter coin values: ";
    for(int i=0;i<n;i++)
        cin>>coins[i];

    int amount;

    cout<<"Please enter target amount: ";
    cin>>amount;

    cout<<"Minimum coins required: "<<coinChange(coins, amount);

    return 0;
}