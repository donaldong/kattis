#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int total = 1;
  while(n > k) {
    total++;
    n -= ceil(double(n) / k);
  }
  total += n;

  cout << total << endl;
  return 0;
}
