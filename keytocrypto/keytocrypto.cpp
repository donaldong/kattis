#include <bits/stdc++.h>
using namespace std;

int main() {
  string cipher, key;
  cin >> cipher >> key;
  for (size_t i = 0; i < cipher.size(); ++i) {
    char c = (cipher[i] - key[i] + 26) % 26 + 'A';
    key += c;
    cout << c;
  }
  cout << endl;
  return 0;
}
