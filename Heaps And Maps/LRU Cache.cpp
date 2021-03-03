// By vishwam Shriram mundada
// https://www.interviewbit.com/problems/lru-cache/
// Good question
/*
Algorithm Outline:

LRUCache()
1. key -> (addr, value)
2. List, will contain keys
3. cap=capacity

Get
1. if found, update for key, return. Else -1

Put
1. if exist, update.
2. else add
3. move to first
4. if >capacity, remove last in list i.e. LRU

update
1. erase element
2. add to first
3. store first addr in ht
*/

// This header is necessary because default header used in interviewbit does not contain list
#include<bits/stdc++.h>

map<int, pair<list<int> :: iterator, int> > m;
list<int> l;
int cap = 0;

LRUCache::LRUCache(int capacity) {
    m.clear();
    l.clear();
    cap = capacity;
}

void update(int key)
{
    l.erase(m[key].first);
    l.push_front(key);
    m[key].first = l.begin();
}

int LRUCache::get(int key) {
    if(m.find(key) == m.end())
        return -1;
        
    update(key);
    return m[key].second;
}

void LRUCache::set(int key, int value) {
    if(m.find(key) != m.end())
    {
        m[key].second = value;
        update(key);
    }
    else
    {
        l.push_front(key);
        m[key] = {l.begin(), value};
    }

    if(l.size() > cap)
    {
        m.erase(l.back());
        l.pop_back();
    }
}
