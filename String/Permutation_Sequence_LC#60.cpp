#include<iostream>
#include<vector>
#include<string>
using namespace std;

string getPermutation(int n, int k){

    vector<int> availableNumbers;
    int factorial=1;

    for(int i=1;i<n;i++){
        factorial*=i; // stores (n-1)!
        availableNumbers.push_back(i);
    }

    availableNumbers.push_back(n);

    k--; // convert to 0-based indexing

    string permutation="";

    while(true){

        int currentIndex=k/factorial;

        permutation+=to_string(availableNumbers[currentIndex]); // choose digit belonging to current block

        availableNumbers.erase(availableNumbers.begin()+currentIndex); // remove chosen digit

        if(availableNumbers.empty())
            break;

        k%=factorial; // move inside selected block

        factorial/=availableNumbers.size(); // next block size becomes (remaining-1)!
    }

    return permutation;
}

int main(){

    int n,k;

    cout<<"Please enter n: ";
    cin>>n;

    cout<<"Please enter k: ";
    cin>>k;

    cout<<"Kth Permutation: "<<getPermutation(n,k);

    return 0;
}