// 很有意思的一道题, 递增递减的差分使用很有意思
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, h;
    cin >> n >> m >> h;

    vector <array <int, 2>> a (m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    int l = 0, r = m;
    vector <int> diff (n + 1), pre (n + 1);

    auto check = [&] (int mid) -> bool {
        ranges :: fill (diff, 0LL);
        ranges :: fill (pre, 0LL);

        for (int i = 1; i <= mid; i ++) {
            auto [x, y] = a[i];
            int ll = max (1LL, x - y + 1);

            // cout << ll << ' ' << rr << '\n';
            diff[ll] += y - abs(ll - x);
            if (ll + 1 <= n) {
                diff[ll + 1] -= (y - abs(ll - x) - 1);
            }
            if (x + 1 <= n) diff[x + 1] -= 2;
            if (x + y + 1 <= n)  diff[x + y + 1] += 1;
        }

        
        for (int i = 1; i <= n; i ++) {
            pre[i] = pre[i - 1] + diff[i];
        }
        for (int i = 1; i <= n; i ++) {
            pre[i] = pre[i - 1] + pre[i];
            // cout << pre[i] << ' ';
            if (pre[i] > h) return true;
        }

        // cout << '\n';
        return false;
    };

    check (1);
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check (mid)) r = mid - 1;
        else l = mid + 1;
    }

    if (l > m) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n' << l << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}