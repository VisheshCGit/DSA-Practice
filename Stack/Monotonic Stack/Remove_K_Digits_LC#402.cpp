#include <iostream>
#include <deque>
#include <string>
using namespace std;

string removeKdigits(string num, int k){
    deque<int> st; //maintains digits in increasing order

    for(char &ch:num){
        int digit=ch-'0';

        while(!st.empty() && st.back()>digit && k>0){
            st.pop_back(); //remove larger digit because current smaller digit gives a smaller number
            k--;
        }

        st.push_back(digit); //insert current digit
    }

    while(k>0 && !st.empty()){
        st.pop_back(); //remove remaining largest digits from the end
        k--;
    }

    while(!st.empty() && st.front()==0)
        st.pop_front(); //remove leading zeros

    string ans;

    while(!st.empty()){
        ans.push_back(st.front()+'0');
        st.pop_front();
    }

    if(ans.empty())
        return "0";

    return ans;
}

int main(){
    string num;
    int k;

    cout<<"Enter number: ";
    cin>>num;

    cout<<"Enter k: ";
    cin>>k;

    cout<<"Smallest Number: "<<removeKdigits(num,k);

    return 0;
}