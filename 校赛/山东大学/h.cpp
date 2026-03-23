
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int h; cin >> h;

    int now = 10000, dt = 10000;

    int pre = 0;
    int cnt = 0;
    int T = 20;
    int count = 0;
    while (1) {
        if (now == h) {
            cout << "? " << h << '\n';
            cout << ">= " << '\n';
            count++;
            if (dt == 1) {
                cout << "! " << h << '\n';
                return;
            }
            dt /= 100;
            now = pre + dt;
            if (count == 321) return;
            if (++cnt == 3) {
                return;
            }
        } else if (now > h) {
            count++;
            cout << "? " << now << '\n';
            cout << ">=" << '\n';
            dt /= 100;
            if (dt == 0) return;
            now = pre + dt;
            if (++cnt == 3) {
                return;
            }            
        } else if (now < h) {
            count++;
            cout << "? " << now << '\n';
            cout << "<" << '\n';
            pre = now;
            now += dt;
        }
        if (count == 321) return;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}