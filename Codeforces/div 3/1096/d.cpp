
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (2 * n + 1);

    int x = -1, y = -1;
    for (int i = 1; i <= 2 * n; i ++) {
        cin >> a[i];
        if (a[i] == 0) {
            if (x == -1) {
                x = i;
            } else {
                y = i;
            }
        }
    }

    int mx1 = 0;

    // 第一个
    vector <int> b (n + 1);
    for (int i = x; i <= 2 * n && 2 * x - i >= 1; i ++) {
        if (a[i] == a[2 * x - i]) {
            b[a[i]] = 1;
        } else {
            break;
        }
    }

    for (int i = 0; i <= n - 1; i ++) {
        if (b[i]) mx1 = i + 1;
        else break;
    }

    int mx2 = 0;

    // 两边
    vector <int> c (n + 1);
    int ok = 0;
    for (int i = x; i <= (x + y) / 2; i ++) {
        if (a[i] == a[x + y - i]) {
            c[a[i]] = 1;
        } else {
            ok = 1;
            break;
        }
    }

    if (!ok) {
        for (int i = x - 1; i >= 1 && (x + y - i) <= 2 * n; i --) {
            if (a[i] == a[x + y - i]) {
                c[a[i]] = 1;
            } else {
                break;
            }
        }
    }

    if (!ok) {
        for (int i = 0; i <= n - 1; i ++) {
            if (c[i]) mx2 = i + 1;
            else break;
        }   
    }
 

    int mx3 = 0;

    // 22
    vector <int> d (n + 1);
    for (int i = y; i <= 2 * n && 2 * y - i >= 1; i ++) {

        if (a[i] == a[2 * y - i]) {
            d[a[i]] = 1;
        } else {
            break;
        }
        
    }

    for (int i = 0; i <= n - 1; i ++) {
        if (d[i]) mx3 = i + 1;
        else break;
    }  

    // cerr << "x : " << x << ' ' << y << '\n';
    // cerr << "mx : " << mx1 << ' ' << mx2 << ' ' << mx3 << '\n';

    cout << max ({mx1, mx2, 1LL, mx3}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}