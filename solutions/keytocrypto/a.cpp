#include <bits/stdc++.h>
using namespace std;

int main() {
  string encrypted, key, message = "";
  string tempKey = "";
  int keyIndex = 0;

  cin >> encrypted >> key;

  message = encrypted;
  for (int i = 0; i < encrypted.length(); i++) {
    message[i] = ((26+encrypted[i]-key[keyIndex])%26) + 'A';
    cout << message[i];
    tempKey += message[i];
    keyIndex++;
    if (keyIndex == key.length()) {
      keyIndex = 0;
      key = tempKey;
      tempKey = "";
    }
  }
}
