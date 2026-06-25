#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeSubstring(string s, int k){
    stack<pair<char,int>> st; //{bracket, consecutive frequency}

    for(char &ch : s){
        if(st.empty())
            st.push({ch,1}); //first group
        else if(st.top().first==ch)
            st.top().second++; //increase frequency of current group
        else
            st.push({ch,1}); //start a new group

        if(!st.empty() && st.top().first==')' && st.top().second==k){ //k consecutive ')' found
            auto curr=st.top();
            st.pop();

            if(!st.empty() && st.top().second>=k){ //check if k '(' exist just below
                st.top().second-=k; //remove k '('

                if(st.top().second==0)
                    st.pop(); //remove group if frequency becomes zero

                continue;
            }

            st.push(curr); //restore ')' group if matching '(' not found
        }
    }

    string ans;

    while(!st.empty()){
        auto curr=st.top();
        st.pop();

        for(int i=0;i<curr.second;i++)
            ans.push_back(curr.first); //reconstruct original string
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    string s;
    int k;

    cout<<"Enter string: ";
    cin>>s;

    cout<<"Enter k: ";
    cin>>k;

    cout<<"Final String: "<<removeSubstring(s,k);

    return 0;
}