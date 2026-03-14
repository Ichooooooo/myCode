
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <array<int, 3>> b (m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }

    vector <int> diff (n + 1);
    auto check = [&] (int mid) -> bool  {
        fill (diff.begin(), diff.end(), 0);
        for (int i = 1; i <= mid; i ++) {
            auto [x, y, z] = b[i];
            diff[y] += x;
            if (z + 1 <= n)
            diff[z + 1] -= x;
        }

        int pre = 0;
        for (int i = 1; i <= n; i ++) {
            pre += diff[i];
            if (pre > a[i]) return true;
        }
        return false;
    };

    int l = 1, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check (mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (l > m) {
        cout << 0 << '\n';
    } else {
        cout << -1 << '\n' << l << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}