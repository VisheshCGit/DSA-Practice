#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(int k, vector<int>& piles, int h){
    long long hours = 0;

    for(int i=0; i<piles.size(); i++){
        if(piles[i] <= k)
            hours++;
        else{
            hours += piles[i] / k;

            if(piles[i] % k != 0)
                hours++;
        }

        if(hours > h)
            return false;
    }

    return true;
}

int minEatingSpeed(vector<int>& piles, int h){
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    int answer = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(check(mid, piles, h)){
            answer = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return answer;
}

int main(){
    int n;

    cout<<"Please enter number of piles: ";
    cin>>n;

    vector<int> piles(n);

    cout<<"Please enter bananas in each pile: ";
    for(int i=0; i<n; i++){
        cin>>piles[i];
    }

    int h;

    cout<<"Please enter total hours available: ";
    cin>>h;

    int result = minEatingSpeed(piles, h);

    cout<<"Minimum eating speed required: "<<result<<endl;

    return 0;
}