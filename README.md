
# LRU Cache Implementation in C++

This project implements a Least Recently Used (LRU) Cache in C++. An LRU Cache is a type of cache that removes the least recently used item when the cache reaches its maximum capacity.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Performance](#performance)
- [License](#license)

## Overview

The LRU Cache is implemented using two main components:
- A **doubly linked list** (`std::list`) to maintain the order of elements based on usage (most recently used at the front and least recently used at the back).
- An **unordered map** (`std::unordered_map`) to quickly lookup elements in the cache by their values.

This combination ensures that both cache insertions and lookups are performed in **O(1)** time, making it efficient for real-time applications requiring fast access to cached data.

## Features

- **Efficient Lookup**: The cache allows fast O(1) access for checking if an element is in the cache and for adding/removing elements.
- **LRU Eviction Policy**: When the cache reaches its maximum size, the least recently used element is evicted to make room for new elements.
- **Cache Size Limit**: The size of the cache is configurable, and it automatically handles evictions when the limit is exceeded.

## How It Works

The LRU Cache works by maintaining a list that stores the elements in the order of their usage. The most recently used element is moved to the front of the list, while the least recently used element is at the back. When the cache exceeds its size limit, the element at the back (the least recently used) is removed.

### Operations:
- **Access an element**: When you access an element, it is moved to the front of the list (most recently used).
- **Insert a new element**: If the element is not already in the cache, it is added to the front. If the cache is full, the least recently used element is evicted.
- **Display the cache**: You can view the current elements in the cache in their order of usage.

## Usage

### Example

```cpp
#include <iostream>
#include "LRUCache.h"

int main() {
    // Create an instance of LRUCache with a max size of 3
    LRUCache lruCache(3);

    // Simulate accessing cache elements
    lruCache.accessCache(4);
    lruCache.accessCache(5);
    lruCache.accessCache(6);
    lruCache.accessCache(5);  // Moves 5 to the front
    lruCache.accessCache(4);  // Moves 4 to the front
    lruCache.accessCache(1);  // Removes least recently used element (6)
    lruCache.accessCache(3);  // Removes least recently used element (5)

    // Display the current cache
    lruCache.displayCache();

    return 0;
}
```

### Output:
```
Time taken by function: [duration] microseconds
3 1 4
```

## Performance

- **Time Complexity**:
  - **Insertion**: O(1) due to the use of `unordered_map` for fast lookup and `list` for efficient insertion/removal.
  - **Lookup**: O(1) due to the `unordered_map`.
  - **Eviction**: O(1) when the cache size exceeds the limit.
- **Space Complexity**: O(n), where `n` is the maximum number of elements that can be stored in the cache.

