#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList){
    unordered_set<string> words(wordList.begin(), wordList.end());

    queue<pair<string,int>> q;
    q.push({beginWord,1});

    if(words.count(beginWord))
        words.erase(beginWord);

    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        string word=curr.first;
        int steps=curr.second;

        if(word==endWord)
            return steps;

        for(int i=0;i<word.size();i++){
            string nextWord=word;

            for(char ch='a';ch<='z';ch++){
                nextWord[i]=ch;

                if(words.count(nextWord)){
                    q.push({nextWord,steps+1});
                    words.erase(nextWord);    // Mark visited
                }
            }
        }
    }

    return 0;
}

int main(){
    string beginWord,endWord;
    int n;

    cout<<"Enter begin word: ";
    cin>>beginWord;

    cout<<"Enter end word: ";
    cin>>endWord;

    cout<<"Enter number of words: ";
    cin>>n;

    vector<string> wordList(n);

    cout<<"Enter words:\n";
    for(int i=0;i<n;i++)
        cin>>wordList[i];

    cout<<"Shortest Transformation Length: "
        <<ladderLength(beginWord,endWord,wordList);

    return 0;
}