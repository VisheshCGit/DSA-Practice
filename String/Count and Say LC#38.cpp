#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n){

    if(n==1)
        return "1";

    string prev="1";

    for(int i=2;i<=n;i++){

        string curr;
        int count=0;
        char current=prev[0];
        int j=0;

        while(j<prev.size()){

            while(j<prev.size() && prev[j]==current){
                count++;
                j++;
            }

            curr.push_back(count+'0'); //store frequency
            curr.push_back(current); //store current digit

            count=0;

            if(j<prev.size())
                current=prev[j]; //start counting the next group
        }

        prev=curr; //current string becomes previous for next iteration
    }

    return prev;
}

int main(){

    int n;

    cout<<"Enter n : ";
    cin>>n;

    cout<<countAndSay(n);

    return 0;
}