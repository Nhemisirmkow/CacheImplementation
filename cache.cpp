#include "cache.h"

template <typename K, typename V>
Cache<K, V>::Cache(int maxSize) {
    this->m = std::unordered_map<K, CacheValue<V>>();
    this->callQueue = std::queue<K>();
    this->maxSize = maxSize;
}


// Erases all values from queue (operations/entries) until one of the keys has
// call number equal 0 -- then we assume it's too old and erase it from hashmap
// and finish our function. We will erase at most the same number of entries as
// many get/put calls we had -- amortized complexity.
template <typename K, typename V>
void Cache<K, V>::makeCleanUp() {
  while (!callQueue.empty()) {
    K oldKey = callQueue.front();
    callQueue.pop();
    auto el = &m[oldKey];
    el->touchQueueCounter--;
    if (el->touchQueueCounter == 0) {
      m.erase(oldKey);
      break;
    }
  }
}

// Here we first check if key exists -- if yes, we add operation to the queue
// and then we add number of calls for the key and return the value.
// If key not found -- return default constructor.
template <typename K, typename V>
V Cache<K, V>::get(K key) {
  if (m.find(key) != m.end()) {
    callQueue.push(key);

    auto el = &m[key];
    el->touchQueueCounter++;

    return el->val;
  }

  return V();
}

// First we add put operation to the queue.
// Then we lookup for a key. If it exists -- we change it's value and then
// we update it's number of last calls (we add operation to the queue list)
// If a key is not found -- we create a new CacheValue. If there is no space
// we erase unnecessary calls until one of the values is completely forgotten.
template <typename K, typename V>
void Cache<K, V>::put(K key, V val) {
  callQueue.push(key);

  if (m.find(key) != m.end()) {
    auto el = &m[key];
    el->touchQueueCounter++;
    el->val = val;
  }
  else {
    CacheValue<V> el;
    el.touchQueueCounter = 1;
    el.val = val;

    if (m.size() == maxSize) {
      makeCleanUp();
    }

    m[key] = el;
  }
}
