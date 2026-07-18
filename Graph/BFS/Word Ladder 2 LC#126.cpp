#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList){
    vector<vector<string>> ans;
    unordered_set<string> words(wordList.begin(), wordList.end());

    queue<vector<string>> q;
    q.push({beginWord});

    while(!q.empty()){
        int size=q.size();
        unordered_set<string> toBeRemoved;

        while(size--){
            auto path=q.front();
            q.pop();

            string lastWord=path.back();

            if(lastWord==endWord){
                ans.push_back(path);

                while(!q.empty()){
                    auto currPath=q.front();
                    q.pop();

                    if(currPath.back()==endWord)
                        ans.push_back(currPath);
                }

                return ans;
            }

            for(int i=0;i<lastWord.size();i++){
                string word=lastWord;
                char original=word[i];

                for(char ch='a';ch<='z';ch++){
                    if(ch==original)
                        continue;

                    word[i]=ch;

                    if(words.count(word)){
                        auto newPath=path;
                        newPath.push_back(word);

                        q.push(newPath);
                        toBeRemoved.insert(word);
                    }
                }
            }
        }

        for(auto &word:toBeRemoved)
            words.erase(word);
    }

    return ans;
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

    vector<vector<string>> ans=findLadders(beginWord,endWord,wordList);

    if(ans.empty()){
        cout<<"No transformation sequence exists.\n";
        return 0;
    }

    cout<<"\nShortest Transformation Sequences:\n";

    for(auto &path:ans){
        for(auto &word:path)
            cout<<word<<" ";
        cout<<"\n";
    }

    return 0;
}