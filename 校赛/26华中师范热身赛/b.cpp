
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    string s; cin >> s;
    double n = stod (s);
    if (s == "Inf") cout << 0 << '\n';
    else if (s == "nan") cout << "NaN" << '\n';
    else  {
        cout << fixed << setprecision(10) << double(1.0 / n) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}