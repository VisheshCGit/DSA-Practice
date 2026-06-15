#include<iostream>
#include<vector>
using namespace std;

int solve(int index, vector<int>& coins, int remainingAmount){

    if(remainingAmount==0)
        return 0; // target formed successfully

    if(remainingAmount<0 || index==coins.size())
        return 1e9; // impossible path

    int take=1+solve(index, coins, remainingAmount-coins[index]); // reuse same coin

    int notTake=solve(index+1, coins, remainingAmount); // move to next coin

    return min(take, notTake);
}

int coinChange(vector<int>& coins, int amount){

    int answer=solve(0, coins, amount);

    return (answer>=1e9) ? -1 : answer;
}

int main(){

    int numberOfCoins;

    cout<<"Please enter number of coins: ";
    cin>>numberOfCoins;

    vector<int> coins(numberOfCoins);

    cout<<"Please enter coin values: ";
    for(int i=0;i<numberOfCoins;i++)
        cin>>coins[i];

    int amount;

    cout<<"Please enter target amount: ";
    cin>>amount;

    cout<<"Minimum coins required: "<<coinChange(coins, amount);

    return 0;
}