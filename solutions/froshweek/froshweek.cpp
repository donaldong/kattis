#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<tuple<int, int>> vtup;
typedef vector<ll> vl;

#define LSB(i) ((i) & -(i))

vl st;

ll sum(int i) {
  ll res = 0;
  while (i > 0) {
    res += st[i], i -= LSB(i);
  }
  return res;
}

void add(int i, int v) {
  while (i < st.size()) {
    st[i] += v, i += LSB(i);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n;
  vtup N(n);
  for (int i = 0; i < n; ++i) {
    cin >> k;
    N[i] = {k, i};
  }
  sort(N.begin(), N.end());
  vi nums(n);
  for (int i = 0; i < n; ++i) {
    nums[get<1>(N[i])] = i + 1;
  }

  st.assign(n + 1, 0);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += sum(n) - sum(nums[i]);
    add(nums[i], 1);
  }
  printf("%lld\n", res);
  return 0;
}
