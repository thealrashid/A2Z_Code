#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    private:
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        dll.splice(dll.begin(), dll, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            dll.splice(dll.begin(), dll, mp[key]);
        } else {
            if (dll.size() == capacity) {
                int oldKey = dll.back().first;
                dll.pop_back();
                mp.erase(oldKey);
            }
            dll.push_front({key, value});
            mp[key] = dll.begin();
        }
    }
};

int main() {
    LRUCache *obj = new LRUCache(5);
    obj->put(1, 3);
    int param_1 = obj->get(1);

    cout << param_1 << endl;

    return 0;
}