#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

struct car {
  string name;
  int catalog, pick_up, cost_per_km;
};

struct spy {
  string name;
  int car = -1;
  ull tot = 0;
  spy() {}
  spy(const string &name) : name(name) {}
};

typedef vector<car> cars;
typedef vector<spy> spies;
typedef unordered_map<string, int> hmap;

int get_spy(const string &s, spies &S, hmap &sid) {
  if (sid.find(s) != sid.end()) return sid[s];
  int res = sid.size();
  sid[s] = res;
  S.push_back(spy(s));
  return res;
}

void handle_event(cars &C, spies &S, hmap &cid, hmap &sid) {
  int t, c, s, a, b, d;
  string sname, action, cname;
  cin >> t >> sname >> action;
  s = get_spy(sname, S, sid), a = action[0];
  if (a == 'p') { // pick up
    cin >> cname, c = cid[cname];
    if (S[s].tot == -1) return;
    if (S[s].car >= 0) { S[s].tot = -1; return; }
    S[s].car = c, S[s].tot += C[c].pick_up;
  } else if (a == 'r') { // return
    cin >> d;
    if (S[s].tot == -1) return;
    if (S[s].car < 0) { S[s].tot = -1; return; }
    c = S[s].car;
    S[s].tot += C[c].cost_per_km * d, S[s].car = -1;
  } else { // accident
    cin >> d;
    if (S[s].tot == -1) return;
    if (S[s].car < 0) { S[s].tot = -1; return; }
    c = S[s].car, b = C[c].catalog * d;
    S[s].tot += b / 100 + (b % 100 ? 1 : 0);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cars C(n);
    spies S;
    hmap cid, sid;
    for (int i = 0; i < n; ++i) {
      auto &c = C[i];
      cin >> c.name >> c.catalog >> c.pick_up >> c.cost_per_km;
      cid[c.name] = i;
    }
    for (int i = 0; i < m; ++i) handle_event(C, S, cid, sid);
    sort(S.begin(), S.end(), [](const spy &a, const spy &b) {
      return a.name < b.name;
    });
    for (auto &s : S) {
      printf("%s ", s.name.c_str());
      if (s.tot == -1 || s.car >= 0) printf("INCONSISTENT\n");
      else printf("%llu\n", s.tot);
    }
  }
  return 0;
}
