#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> v2i;

#define LSB(i) (i & -i)


void add(vi &st, int i, int v) {
  for (; i < st.size(); i += LSB(i)) st[i] += v;
}

ll query(vi &st, int i) {
  ll res = 0;
  for (; i; i -= LSB(i)) res += st[i];
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int num_gems, num_queries, cmd, a, b;
  cin >> num_gems >> num_queries;
  vi V(6);
  v2i ST(6, vi(num_gems + 1, 0));
  for (ll &v : V) cin >> v;
  string gem_types;
  cin >> gem_types;
  vi T(num_gems + 1);
  for (int i = 1; i <= num_gems; ++i) {
    T[i] = gem_types[i - 1] - '1';
    add(ST[T[i]], i, 1);
  }
  while (num_queries--) {
    cin >> cmd >> a >> b;
    switch (cmd) {
      case 1: add(ST[T[a]], a, -1), T[a] = b - 1, add(ST[T[a]], a, 1); break;
      case 2: V[a - 1] = b; break;
      case 3: {
        ll res = 0;
        for (int i = 0; i < 6; ++i) {
          res += V[i] * (query(ST[i], b) - query(ST[i], a - 1));
        }
        printf("%lld\n", res);
      }
    }
  }
  return 0;
}
