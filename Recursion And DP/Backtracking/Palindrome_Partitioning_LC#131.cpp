#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(int left, int right, string& str){

    while(left<right){

        if(str[left]!=str[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void generatePartitions(int index, string& str, vector<string>& currentPartition, vector<vector<string>>& allPartitions){                  
    if(index==str.size()){
        allPartitions.push_back(currentPartition); // one valid partition found
        return;
    }
    for(int end=index; end<str.size(); end++){
        if(isPalindrome(index,end,str)){

            currentPartition.push_back(str.substr(index,end-index+1)); // choose palindrome substring

            generatePartitions(end+1,  str, currentPartition,  allPartitions);  //partition is made till index end.. now check further string palindromes after the partition index                                                              
            currentPartition.pop_back(); // backtracking step...
        }
    }
}

vector<vector<string>> partition(string str){

    vector<vector<string>> allPartitions;
    vector<string> currentPartition;

    generatePartitions(0, str, currentPartition, allPartitions);
    return allPartitions;
}

int main(){

    string str;

    cout<<"Please enter string: ";
    cin>>str;

    vector<vector<string>> answer=partition(str);

    cout<<"All Palindrome Partitions:"<<endl;

    for(auto partition : answer){

        cout<<"[ ";

        for(auto substring : partition)
            cout<<substring<<" ";

        cout<<"]"<<endl;
    }

    return 0;
}