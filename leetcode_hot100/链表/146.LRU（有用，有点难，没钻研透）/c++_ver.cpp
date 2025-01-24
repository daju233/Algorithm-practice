class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;//没有就返回-1
        auto key_value = *map[key];//解引用 迭代器？
        cache.erase(map[key]);//删除链表中的元素
        cache.push_front(key_value);//用过的有用的放最前面
        map[key] = cache.begin();//更新哈希表
        return key_value.second;
    }

    void put(int key, int value) {
        if (map.find(key) == map.end()) {//没找到但是超过容量，就删最早的
            if (cache.size() == cap) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else {
            cache.erase(map[key]);//找到了就直接删
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
        //重新加入
    }
};
