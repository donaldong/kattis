#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map

// Projects
hmap<string, vector<string>> P;
// Students
hmap<string, vector<string>> S;

void output() {
  for (auto &entry : P) {
    auto &V = entry.second;
    sort(V.begin(), V.end());
    auto end = unique(V.begin(), V.end());
    int size = distance(V.begin(), end);
    V.resize(size);
    for (auto itr = V.begin(); itr != V.end(); ++itr) {
      S[*itr].push_back(entry.first);
    }
  }
  vector<pair<string, int>> res;
  for (auto &entry : P) {
    int count = 0;
    for (auto &s : entry.second) {
      if (S[s].size() == 1) ++count;
    }
    res.push_back(make_pair(entry.first, count));
  }
  sort(res.begin(), res.end(), [](pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
  });
  for (auto &p : res) cout << p.first << " " << p.second << endl;
  P.clear();
  S.clear();
}

bool is_project(string &project) {
  return project[0] >= 'A' && project[0] <= 'Z';
}

void add_student_to_project(string &project, string &student) {
  P[project].push_back(student);
}

int main() {
  string line;
  string p;
  while (getline(cin, line)) {
    bool a = line == "1";
    bool b = line == "0";
    if (a || b) {
      p.clear();
      output();
    }
    if (a) continue;
    if (b) break;
    if (is_project(line)) {
      p = line;
      P[line] = vector<string>();
    } else add_student_to_project(p, line);
  }
  return 0;
}
