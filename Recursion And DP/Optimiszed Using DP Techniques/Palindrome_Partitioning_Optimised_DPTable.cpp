#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generatePartitions(int index,string &str,vector<string> &currentPartition,
                        vector<vector<string>> &allPartitions,
                        vector<vector<bool>> &isPalindrome){

    if(index==str.size()){
        allPartitions.push_back(currentPartition); // one valid partition formed
        return;
    }

    for(int end=index;end<str.size();end++){

        if(isPalindrome[index][end]){ // substring str[index...end] is palindrome

            currentPartition.push_back(str.substr(index,end-index+1)); // choose palindrome substring

            generatePartitions(end+1,str,currentPartition,
                               allPartitions,isPalindrome);

            currentPartition.pop_back(); // backtrack
        }
    }
}

vector<vector<string>> partition(string str){

    int n=str.size();

    vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));

    for(int i=0;i<n;i++)
        isPalindrome[i][i]=true; // every single character is palindrome

    for(int i=n-1;i>=0;i--){

        for(int j=i+1;j<n;j++){

            if(str[i]==str[j]){ // first and last character must match

                if(j-i==1)
                    isPalindrome[i][j]=true; // length 2 palindrome like "aa"

                else
                    isPalindrome[i][j]=isPalindrome[i+1][j-1]; // middle part must also be palindrome
            }
        }
    }

    vector<vector<string>> allPartitions;
    vector<string> currentPartition;

    generatePartitions(0,str,currentPartition,
                       allPartitions,isPalindrome);

    return allPartitions;
}

int main(){

    string str;

    cout<<"Please enter string: ";
    cin>>str;

    vector<vector<string>> answer=partition(str);

    cout<<"Palindrome Partitions:"<<endl;

    for(auto partition : answer){

        cout<<"[ ";

        for(auto substring : partition)
            cout<<substring<<" ";

        cout<<"]"<<endl;
    }

    return 0;
}