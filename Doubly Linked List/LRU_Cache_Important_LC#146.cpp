#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
    list<pair<int,int>> cache; //front = LRU, back = MRU
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int capacity;

public:
    LRUCache(int capacity){
        this->capacity=capacity;
    }

    int get(int key){
        if(mp.find(key)==mp.end())
            return -1;

        auto it=mp[key];
        cache.splice(cache.end(),cache,it); //move accessed node to the back in O(1)

        return it->second;
    }

    void put(int key,int value){

        if(mp.find(key)!=mp.end()){ //Now this becomes Recently used key so put it at front of list
            auto it=mp[key];
            cache.splice(cache.end(),cache,it); //move existing node to MRU position
            it->second=value; //update value
            return;
        }

        if(cache.size()==capacity){
            mp.erase(cache.front().first); //remove LRU key from hashmap
            cache.pop_front(); //remove LRU node
        }

        cache.push_back({key,value}); //insert new node as MRU
        mp[key]=prev(cache.end()); //store iterator of newly inserted node
    }
};

int main(){

    LRUCache cache(2);

    cache.put(1,10);
    cache.put(2,20);

    cout<<cache.get(1)<<endl;

    cache.put(3,30);

    cout<<cache.get(2)<<endl;
    cout<<cache.get(3)<<endl;

    return 0;
}