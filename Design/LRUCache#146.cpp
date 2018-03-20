#include <iostream>
#include <string>

#include <list>
#include <unordered_map>

class LRUCache {
    int cap_ {0};
    std::list<std::pair<int,int>> val_l_;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> it_map_;
public:
    LRUCache(int capacity): cap_(capacity) {
        
    }
    
    int get(int key) {
        auto got = it_map_.find(key);
        if (got == it_map_.end()) return -1;
        auto value = got->second->second;
        val_l_.erase(got->second);
        val_l_.push_front({key,value});
        it_map_[key] = val_l_.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto got = it_map_.find(key);
        if (got != it_map_.end()) {//found
            val_l_.erase(got->second);
            val_l_.push_front({key,value});
            it_map_[key] = val_l_.begin();
        }
        else {//not found
            if(val_l_.size() == cap_)
            {
                it_map_.erase(val_l_.rbegin()->first);
                val_l_.pop_back();
            }

            val_l_.push_front({key,value});
            it_map_[key] = val_l_.begin();
        }
    }

    void print_list() {
        std::cout << "Listed values : " << std::endl;
        for (auto it = val_l_.begin(); it != val_l_.end(); ++it) {
            std::cout << "\t" << it->first << ":" << it->second << std::endl;
        }
        
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
int main()
{

  //LRUCache lru_cache(2);
  //lru_cache.print_list();
  LRUCache* obj = new LRUCache(2);
  obj->put(1,1);
  obj->put(2,2);
  obj->print_list();
  obj->get(1);
  obj->print_list();
  obj->put(3,3);
  obj->print_list();
  auto ret = obj->get(2);
  std::cout << "Returned value is " << ret << std::endl;

}

