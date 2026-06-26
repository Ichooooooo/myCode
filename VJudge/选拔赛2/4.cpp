// int范围2e9, 2^31 - 1
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> s(n), e(n), d(n), cnt (n);
    int cn = 0;
    for (int i = 0; i < n; i ++) {
        cin >> s[i] >> e[i] >> d[i];
        cnt[i] = (e[i] - s[i]) / d[i] + 1;
        cn += cnt[i];
    }

    if (cn % 2 == 0) {
        cout << "There's no weakness." << '\n';
        return;
    }

    auto check = [&] (int mid) -> bool {
        int cl = 0, cr =0;
        for (int i = 0; i < n; i ++) {
            if (e[i] <= mid) {
                cl += cnt[i];
            } else if (s[i] > mid) {
                cr += cnt[i];
            } else {
                cl += (mid - s[i]) / d[i] + 1;
                cr += max(0LL, (e[i] - mid - 1) / d[i] + 1);
            }
        }

        if (cl % 2 == 0) return false;
        else return true;
    };

    int l = 0, r = 3e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int pos = l, ans = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] <= pos && pos <= e[i]) {
            ans += ((pos - s[i]) % d[i] == 0);
        }
    }

    cout << pos << ' ' << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;
    while (_--) ovo();
}
