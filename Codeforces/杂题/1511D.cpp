
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    string s;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            s += char('a' + i);
            if (i != j) s += char('a' + j);
        }
    }

    int sz = s.size();
    int c1 = n / sz;
    int c2 = n % sz;
    string t = s.substr (0, c2);
    for (int i = 0; i < c1; i ++) cout << s;
    cout << t << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}