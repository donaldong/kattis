#include <bits/stdc++.h>
using namespace std;
using Hash = __int128;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  unordered_map<Hash,vector<int>> P;

  auto possible = [&](int len) {
    unordered_map<Hash,vector<int>> P2;
    /*
      since the string is pretty long, we need a big base to avoid collision;
      m=1e9+9 is not good enough (WA)
    */
    const Hash p = 31;
    const Hash m = 984162944621615797;
    vector<Hash> p_pow(s.size());
    p_pow[0] = 1;
    for (int i = 1; i < s.size(); i++) p_pow[i] = (p_pow[i-1] * p) % m;

    vector<Hash> h(s.size()+1, 0);
    for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    bool f = false;
    for (int i = 0; i <= s.size()-len; ++i) {
      long long cur_h = (h[i+len] + m - h[i]) % m;
      cur_h = (cur_h * p_pow[s.size()-i-1]) % m;
      auto& pos = P2[cur_h];
      pos.push_back(i);
      if (pos.size()>=2) f = true;
    }
    if (f) swap(P, P2);
    return f;
  };

  int l = 1, r = s.size();
  while (l<=r) {
    int mid = (l+r)/2;
    if (possible(mid)) l=mid+1;
    else r = mid-1;
  }

  vector<int> pos;
  for (auto& [k, p] : P) {
    if (p.size()<2) continue;
    pos.push_back(p[0]);
  }

  for (int len = l-1; len > 0; --len) {
    vector<int> pos2;
    char c = 'z';
    for (int i : pos) c = min(c, s[i]);
    for (int i : pos) if (s[i] == c) {
      pos2.push_back(i+1);
    }
    swap(pos, pos2);
    cout << c;
  }
  cout << endl;
  return 0;
}
