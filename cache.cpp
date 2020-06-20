#include <iostream>
#include <list>
#include<unordered_map>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;  // to measure time.


class CacheLRU {
  int CacheSize_;
  list<int> CacheMemory;
  unordered_map<int, list<int>::iterator> ref_hashtable_;
  public:
    void CacheLRUFill(int element);
    void DisplayCacheElements();
    CacheLRU (int size) {
      CacheSize_ = size;
    }
};

/*
  @ CacheLRUFill().
  - If element is new, add it to cache.
  - If element is already present, move it to the front.
  - If the cache is full, remove the last element from cache.
  - Linked List + Hash Table, gives time complexity O(1) (contant time).
*/
void CacheLRU::CacheLRUFill(int element) {
  auto it = find(CacheMemory.begin(), CacheMemory.end(), element);
  if(ref_hashtable_.find(element)== ref_hashtable_.end()) {
    if(ref_hashtable_.size() == CacheSize_){
      int pop_element = CacheMemory.back();
      CacheMemory.pop_back();
      ref_hashtable_.erase(pop_element);
    }
  } else {
    CacheMemory.erase(ref_hashtable_.find(element)->second);
  }
  CacheMemory.push_front(element);
  ref_hashtable_[element] = CacheMemory.begin();
}

void CacheLRU::DisplayCacheElements() {
  for(int & it : CacheMemory) {
    cout << it <<" ";
  }
  cout << endl;
}


auto main() -> int {
  // create instance of class.
  CacheLRU cache_lru(3);
  
  // Add cache elements. 
  auto start = high_resolution_clock::now();
  cache_lru.CacheLRUFill(4);
  cache_lru.CacheLRUFill(5);
  cache_lru.CacheLRUFill(6);
  cache_lru.CacheLRUFill(5);
  cache_lru.CacheLRUFill(4);
  cache_lru.CacheLRUFill(1);
  cache_lru.CacheLRUFill(3);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
  // Display cache elements.
  cache_lru.DisplayCacheElements();
  return 0;
}
