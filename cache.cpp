#include <iostream>
#include <list>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace std::chrono;  // to measure time.

class LRUCache {
    int maxCacheSize_;                         // Cache size limit
    list<int> cacheOrder_;                     // To store cache elements in the order they are used
    unordered_map<int, list<int>::iterator> cacheMap_;  // To quickly lookup elements in cache

public:
    explicit LRUCache(int maxSize) : maxCacheSize_(maxSize) {}

    void accessCache(int element);
    void displayCache() const;
};

void LRUCache::accessCache(int element) {
    // Check if the element is already in the cache
    if (cacheMap_.find(element) != cacheMap_.end()) {
        // Remove the element from its current position
        cacheOrder_.erase(cacheMap_[element]);
    }

    // Add the element to the front (most recently used)
    cacheOrder_.push_front(element);
    cacheMap_[element] = cacheOrder_.begin();

    // If the cache exceeds the maximum size, remove the least recently used element (back of the list)
    if (cacheMap_.size() > maxCacheSize_) {
        int leastUsedElement = cacheOrder_.back();
        cacheOrder_.pop_back();
        cacheMap_.erase(leastUsedElement);
    }
}

void LRUCache::displayCache() const {
    for (const int& element : cacheOrder_) {
        cout << element << " ";
    }
    cout << endl;
}

auto main() -> int {
    // Create an instance of the LRUCache with a max size of 3
    LRUCache lruCache(3);

    // Simulate accessing cache elements
    auto start = high_resolution_clock::now();
    lruCache.accessCache(4);
    lruCache.accessCache(5);
    lruCache.accessCache(6);
    lruCache.accessCache(5);
    lruCache.accessCache(4);
    lruCache.accessCache(1);
    lruCache.accessCache(3);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    // Display cache elements
    lruCache.displayCache();
    return 0;
}
