# CacheImplementation
Cache implementation in C++. Presented class supports 2 functions: put and get. Additionaly, Cache keeps only n last keys -- every get and put function refreshes key touched time.

Cache has to support 2 functions:
1. put(K key, V value) -- puts value for a given key.
2. get(K key) -- gets value for a given key (if exists, otherwise returns default constructor for V)

Cache can have at most N key entries (N specified in the initialization).

Given implementation has O(1) time complexity for put and get functions and O(n) space complexity assuming unordered_map in C++ (hashMap) has O(1) time complexity. The only drawback of the solution is that it keeps queue of the entries -- which is used to delete the oldest key if necessary -- we just proceed all the old entries up to the moment one of the keys has 0 entries left in the queue -- it means it is the oldest and we erase it. We add entries every time we call put or get successfully (we keep number of entries in the queue for a given key). Queue cleaning has O(1) amortized complexity because we will empty queue at most N times where N is the number of get/put calls overall. This may lead to problems with memory -- at some point it might be useful to clear queue from old entries (assuming oldest entry isn't the only one for its key). This can be further optimized -- we can keep a list and just skip (erase) all additional entries (these entries in the queue that are not the last ones for their keys). Such Operation can be performed if we start reaching memory limit -- we would make at most M unnecessary operations where M is the limit for a Cache object.


To be added:
more tests wrapped in some class (with assertions).
