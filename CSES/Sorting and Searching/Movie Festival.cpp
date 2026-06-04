
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <arr2> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort (a.begin() + 1, a.end());

    vector <int> vmn (n + 2);

    const int INF = 1e10;
    vmn[n + 1] = INF;
    for (int i = n; i >= 1; i --) {
        vmn[i] = min (vmn[i + 1], a[i][1]);
    }

    int cnt = 1, rt = vmn[1];
    
    while (1) {
        auto pos = lower_bound (a.begin() + 1, a.end(), arr2{rt, -INF});
        if (pos == a.end()) {
            break;
        }

        int p = pos - a.begin();
        cnt++;
        rt = vmn[p];
    }

    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}