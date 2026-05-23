#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness,int k){
    long long totalHappiness=0;
    int size=happiness.size();

    sort(happiness.begin(),happiness.end());

    for(int i=0;i<k;i++){
        if(happiness[size-i-1]-i>0)
            totalHappiness+=happiness[size-i-1]-i;
    }

    return totalHappiness;
}

int main(){
    int size,k;
    cout<<"Enter size of happiness array: "<<"\n";
    cin>>size;

    vector<int> happiness(size);
    for(int i=0;i<size;i++)
        cin>>happiness[i];

    cout<<"Enter number of children to select: ";
    cin>>k;

    cout<<"Answer: "<<maximumHappinessSum(happiness,k);

    return 0;
}