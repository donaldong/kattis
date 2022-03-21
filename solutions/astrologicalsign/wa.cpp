#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> days{
  {"Jan", 0},
  {"Feb", 31},
  {"Mar", 60},
  {"Apr", 91},
  {"May", 121},
  {"Jun", 151},
  {"Jul", 182},
  {"Aug", 213},
  {"Sep", 243},
  {"Oct", 274},
  {"Nov", 305},
  {"Dec", 335},
};

unordered_map<string,pair<int,int>> S{
  {"Aries", {days["Mar"]+21, days["Apr"]+20}},
  {"Taurus", {days["Apr"]+21, days["May"]+20}},
  {"Gemini", {days["May"]+21, days["Jun"]+21}},
  {"Cancer", {days["Jun"]+22, days["Jul"]+22}},
  {"Leo", {days["Jul"]+23, days["Aug"]+22}},
  {"Virgo", {days["Aug"]+23, days["Sep"]+21}},
  {"Libra", {days["Sep"]+22, days["Oct"]+22}},
  {"Scorpio", {days["Oct"]+23, days["Nov"]+22}},
  {"Sagittarius", {days["Nov"]+23, days["Dec"]+21}},
  {"Aquarius", {days["Jan"]+21, days["Feb"]+19}},
  {"Pisces", {days["Feb"]+20, days["Mar"]+20}},
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int d;
    string m;
    cin >> d >> m;
    d += days[m];
    bool found = false;
    for (auto& [name, p] : S) {
      if (d >= p.first && d < p.second) {
        cout << name << endl;
        found = true;
      }
    }
    if (!found) cout << "Capricorn" << endl;
  }
  return 0;
}
