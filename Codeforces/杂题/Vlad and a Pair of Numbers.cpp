
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int yh; cin >> yh;
    int sm = (yh << 1LL);

    int sz = 0, t = sm;
    while(t) {
        sz++;
        t >>= 1;
    }

    vector <int> a (sz), b (sz);
    int pas = 0;

    for (int i = sz - 1; i >= 0; i --) {
        int now = (pas << 1) + ((sm >> i) & 1);
        
        if ((yh >> i) & 1LL) {
            if (now >= 1) {
                if (i & 1) 
                a[i] = 1, b[i] = 0;
                else 
                b[i] = 1, a[i] = 0;
                now -= 1;
            } else {
                now += 1;
            }
        } else {
            if (now >= 2) {
                a[i] = 1, b[i] = 1;
                now -= 2;
            } else {
                a[i] = 0, b[i] = 0;
            } 
        }

        pas = now;
    } 

    if (pas != 0) {
        cout << -1 << '\n';
        return;
    }

    int aa = 0, bb = 0;
    for (int i = sz - 1; i >= 0; i --) {
        aa += (a[i] << i);
        bb += (b[i] << i);
    }

    cout << aa << ' ' << bb << '\n';
    // cerr << "ans : " << (aa + bb) / 2 << ' ' << (aa ^ bb) << '\n'; 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}