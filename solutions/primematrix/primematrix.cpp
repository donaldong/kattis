#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, b;
  cin >> n >> b;

  vi N(n);
  int sum = 0, k = 0;
  for (int i = 0; i < n; ++i) N[i] = i + 1, sum += i + 1;

  while (!is_prime(sum + k)) ++k;
  int i = n - 1;
  while (k)  {
    ++N[i]; --k; --i;
    if (i < 0) i = n - 1;
  }

  if (N.back() > b) printf("impossible\n");
  else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j) printf(" ");
        printf("%d", N[(i + j) % n]);
      }
      printf("\n");
    }
  }

  return 0;
}
