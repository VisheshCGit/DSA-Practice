#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache{
    int cap;
    int minFreq;
    unordered_map<int, pair<int,int>> mp;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity){
        cap=capacity;
        minFreq=0;
    }

    int get(int key){
        if(mp.find(key)==mp.end())
            return -1;

        int value=mp[key].first;
        int freq=mp[key].second;

        freqList[freq].erase(pos[key]);

        if(freqList[freq].empty()){
            freqList.erase(freq);
            if(minFreq==freq)
                minFreq++;
        }

        freq++;

        mp[key].second=freq;
        freqList[freq].push_back(key);
        pos[key]=prev(freqList[freq].end());

        return value;
    }

    void put(int key,int value){
        if(cap==0)
            return;

        if(mp.find(key)!=mp.end()){
            mp[key].first=value;
            get(key);
            return;
        }

        if(mp.size()==cap){
            int removeKey=freqList[minFreq].front();

            freqList[minFreq].pop_front();

            if(freqList[minFreq].empty())
                freqList.erase(minFreq);

            mp.erase(removeKey);
            pos.erase(removeKey);
        }

        mp[key]={value,1};
        freqList[1].push_back(key);
        pos[key]=prev(freqList[1].end());
        minFreq=1;
    }
};

int main(){
    LFUCache cache(2);

    cache.put(1,10);
    cache.put(2,20);

    cout<<"get(1): "<<cache.get(1)<<endl;

    cache.put(3,30);

    cout<<"get(2): "<<cache.get(2)<<endl;
    cout<<"get(3): "<<cache.get(3)<<endl;

    cache.put(4,40);

    cout<<"get(1): "<<cache.get(1)<<endl;
    cout<<"get(3): "<<cache.get(3)<<endl;
    cout<<"get(4): "<<cache.get(4)<<endl;

    return 0;
}