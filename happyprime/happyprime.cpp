#include <bits/stdc++.h>
using namespace std;

int MAX_NUM = 1e4;
vector<int> prime(MAX_NUM + 1, 1), happy(MAX_NUM + 1, -1);

bool is_happy(int n) {
  if (happy[n] >= 0) return happy[n];
  happy[n] = 0;
  int sum = 0; 
  for (int i = n; i > 0; i /= 10) sum += (i % 10) * (i % 10);
  if (is_happy(sum)) return happy[n] = 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  prime[0] = prime[1] = 0, happy[1] = 1;
  for (int i = 2; i <= MAX_NUM; ++i) { // Sieve of Eratosthenes
    if (!prime[i]) continue;
    for (int j = i * i; j <= MAX_NUM; j += i) prime[j] = 0;
  }
  int t, k, m;
  cin >> t;
  while (t--) {
    cin >> k >> m;
    printf("%d %d %s\n", k, m, prime[m] && is_happy(m) ? "YES" : "NO");
  }
  return 0;
}
