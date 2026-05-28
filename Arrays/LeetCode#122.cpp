#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int profit=0;

    for(int i=1;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            profit+=prices[i]-prices[i-1];
        }
    }

    return profit;
}

int main(){
    int n;

    cout<<"Please enter number of days: ";
    cin>>n;

    vector<int> prices(n);

    cout<<"Please enter stock prices: ";
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    int result=maxProfit(prices);

    cout<<"Maximum profit that can be achieved is: "<<result;

    return 0;
}