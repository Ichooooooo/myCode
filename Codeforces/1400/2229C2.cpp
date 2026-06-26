// 1. 按照边界分析, 发现可以拆分成三部分
// 2. 然后发现最贪心的做法
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), suf (n + 2), pre (n + 1);
    
    int mx = 0, sum = 0, pos = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + abs (a[i]);
        sum += a[i];
    }

    for (int i = n; i >= 1; i --) {
        suf[i] = suf[i + 1] + a[i];
    }

    mx = sum;

    for (int i = 1; i <= n; i ++) {
        if (a[i] > 0) {
            int t = -a[i] + pre[i - 1] + suf[i + 1];
            if (t > mx) {
                mx = t;
                pos = i;
            }
        }    
    }

    if (mx == sum) {
        cout << 0 << '\n';
        cout << '\n';
        return;
    }

    vector <int> ans; ans.reserve (n);

    int ok = 1;

    for (int i = pos - 1; i >= 1; i --) {
        if (a[i] * ok > 0) {
            ans.push_back(i);
            ok *= -1;
        }
    }

    ans.push_back(pos);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}