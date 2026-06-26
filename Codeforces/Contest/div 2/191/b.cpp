
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    if (n == 2) {
        cout << 1 << ' ' << 2 << ' ' << 1 << ' ' << 2 << ' ' << 2 << ' ' << 1 << ' ' << 1 << ' ' << 2 << '\n';
        return;
    }
    vector <int> a1 (n), a2 (n), a3 (n), a4 (n);
    int c1 = 0, c2 = 0, c3 = (0 + 1) % n, c4 = (0 + 3) % n;
    a1[c1] = 1, a2[c2] = 1, a3[c3] = 1, a4[c4] = 1;


    for (int i = 2; i <= n; i ++) {
        a1[(c1 + i - 1) % n] = i;
        a2[(c2 + i - 1) % n] = i;
        a3[(c3 + i - 1) % n] = i;
        a4[(c4 + i - 1) % n] = i;
    }

    for (int i = 0; i < n; i ++) {
        cout << a1[i] << ' ';
    }
    for (int i = 0; i < n; i ++) {
        cout << a2[i] << ' ';
    }
    for (int i = 0; i < n; i ++) {
        cout << a3[i] << ' ';
    }
    for (int i = 0; i < n; i ++) {
        cout << a4[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}