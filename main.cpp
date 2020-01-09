#include <bits/stdc++.h>
#include "cache.h"
#include "cache.cpp"

using namespace std;

typedef Cache<int, int> intCache;

// Creates Cache (3, 4, 5) ordered in freshness
intCache simpleCache1() {
  intCache x = intCache(3);
  x.put(2, 3);
  x.put(3, 4);
  x.put(4, 5);
  x.put(5, 6);
  return x;
}

// Creates Cache (2, 4, 5) ordered in freshness
intCache simpleCache2() {
  intCache x = intCache(3);
  x.put(2, 3);
  x.put(3, 4);
  x.get(2);
  x.put(4, 5);
  x.put(5, 6);
  return x;
}

void test1() {
  bool result = true;
  intCache x = simpleCache1();
  result = result && x.get(1) == 0;
  result = result && x.get(2) == 0;
  result = result && x.get(3) == 4;
  result = result && x.get(4) == 5;
  result = result && x.get(5) == 6;
  if (result) {
    cout << "Test 1 passed" << endl;
  }
  else {
    cout << "Test 1 failed" << endl;
  }
  return;
}

void test2() {
  bool result = true;
  intCache x = simpleCache2();
  result = result && x.get(1) == 0;
  result = result && x.get(2) == 3;
  result = result && x.get(3) == 0;
  result = result && x.get(4) == 5;
  result = result && x.get(5) == 6;
  if (result) {
    cout << "Test 2 passed" << endl;
  }
  else {
    cout << "Test 2 failed" << endl;
  }
  return;
}


// test3 -- start with ((2, 3), (4, 5), (5, 6)) cache, then change to
// ((4, 5), (5, 6), (2, 4)) then to ((5, 6), (2, 4), (3, -2)) cache.
void test3() {
  bool result = true;
  intCache x = simpleCache2();
  x.put(2, 4);
  x.put(3, -2);
  result = result && x.get(1) == 0;
  result = result && x.get(2) == 4;
  result = result && x.get(3) == -2;
  result = result && x.get(4) == 0;
  result = result && x.get(5) == 6;
  if (result) {
    cout << "Test 3 passed" << endl;
  }
  else {
    cout << "Test 3 failed" << endl;
  }
  return;
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
