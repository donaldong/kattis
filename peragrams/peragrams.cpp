#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  vector<int> count(26, 0);
  while (cin >> c) ++count[c - 'a'];
  int odd_count = 0;
  for (int c : count) if (c & 1) ++odd_count;
  cout << max(0, odd_count - 1) << endl;
  return 0;
}
