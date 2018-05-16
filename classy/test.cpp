#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            string a, b, c;
            cin >> a >> b >> c;
            cout << i << " " << j;
            cout << a << b << c << endl;
        }
    }
    return 0;
}
