#include <bits/stdc++.h>
using namespace std;

#define LSB(i) (i & -i)

typedef vector<int> vi;
typedef deque<int> dqi;

#ifdef DEBUG
void print(dqi &Q) {
  for (int q : Q) printf("%d ", q);
  printf("\n");
}
#endif

dqi Q;
vi pos, st;

void add(int i, int v) {
  for (; i < st.size(); i += LSB(i)) st[i] += v;
}

int query(int i) {
  int res = 0;
  for (; i; i -= LSB(i)) res += st[i];
  return res;
}

bool match(dqi &A, dqi &B) {
#ifdef DEBUG
  printf("A: "), print(A);
  printf("B: "), print(B);
#endif
  for (int i = 0; i < 3; ++i) if (A[i] != B[i]) return false;
  return true;
}

int index(int n) {
  int i = query(pos[n]);
#ifdef DEBUG
  printf("removed %d elements from position %d to the end\n", i, pos[n]);
#endif
  add(pos[n], 1);
  return pos[n] - i;
}

bool possible() {
  for (int i = 1; Q.size() > 3; ++i) {
#ifdef DEBUG
    print(Q);
#endif
    int p = index(i), q = Q.size() - p;
#ifdef DEBUG
    printf("index_from_end(%d) = %d, from beg = %d\n", i, p, q);
#endif
    Q.erase(Q.end() - p);
    if (q % 2 == 0) continue;
    int a = Q[0], b = Q[1];
    swap(pos[a], pos[b]);
    Q.pop_front(), Q.pop_front();
    Q.push_front(a), Q.push_front(b);
  }
#ifdef DEBUG
  print(Q);
#endif
  int min_val = INT_MAX;
  for (int i = 0; i < 3; ++i) min_val = min(min_val, Q[i]); 
  for (int i = 0; i < 3; ++i) Q[i] -= min_val;
#ifdef DEBUG
  printf("norm => "), print(Q);
#endif
  dqi T = {0, 1, 2};
  for (int i = 0; i < 3; ++i) {
    if (match(Q, T)) return true;
    T.push_front(T.back()), T.pop_back();
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, v;
  cin >> n;
  vi ord(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v, ord[v] = i;
  }
  pos.resize(n + 1), st.assign(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v;
    pos[ord[v]] = n - i;
    Q.push_back(ord[v]);
  }
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) printf("pos[%d] = %d\n", i, pos[i]);
#endif
  printf("%s\n", possible() ? "Possible" : "Impossible");
  return 0;
}
