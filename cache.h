#ifndef CACHE_H
#define CACHE_H

#include <bits/stdc++.h>

using namespace std;

// Helping structure that keeps the info about the value of the key and
// touchQueueCounter which says how many entries are in queue inside Cache
// with a given key.
template<typename V>
struct CacheValue{
  int touchQueueCounter;
  V val;
};

template<typename K, typename V>
class Cache{
private:
  // maxSize must be < memoryLimit / maxSizeMultiplier
  static const int memoryLimit = 8;
  static const int maxSizeMultiplier = 2;
  // Here we keep all keys -- put/get/erase/find into this map is constant O(1)
  std::unordered_map<K, CacheValue<V>> m;
  // This queue keeps info about get/put entries -- time complexity is amortized
  // when we put or get -- we add additional operation in the future.
  // when clearing this queue we will do at most N number of operations, where
  // N is the number of calls of get/put.
  std::list<K> callList;
  // maxSize describes the maximal size of the Cache (kept items).
  int maxSize;
  // This operation is amortized by the number of calls, thus O(1) in the end.
  void makeCleanUp();
  void performOrdinaryCleanUp();

public:
  Cache(int maxSize);

  void put(K key, V value);
  V get(K key);

  int callListSize();
};

#endif
