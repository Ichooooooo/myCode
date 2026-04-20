
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    map <int, int> mp;
    int cnt = 0;
    for (int i = 1; i < n; i ++) {
        if (a[i] >= a[i - 1]) continue;
        else {
            mp[a[i - 1] - a[i]]++;
            cnt++;
            a[i] = a[i - 1];
        }
    }

    int ans = 0;
    int ncnt = 0, nps = -1;
    for (auto [x, y] : mp) {
        if (nps == -1) {
            ans += (x * (cnt - ncnt)) + x;
            nps = x;
            ncnt += y;
        } else {
            ans += ((x - nps) * (cnt - ncnt)) + x - nps;
            nps = x;
            ncnt += y;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}