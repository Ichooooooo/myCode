
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k, m;
    cin >> n >> k >> m;
    int c0 = 0, c1 = 0;
    vector <int> a, b;
    a.reserve(n); b.reserve(n);

    int h, p;
    for (int i = 0; i < n; i ++) {
        cin >> h >> p;
        if (h == 1) {
            a.push_back(p); c0 ++;
        } else {
            b.push_back(p); c1 ++;
        }
    }

    if (c0 < m || c1 < (k - m)) {
        cout << -1 << '\n';
    } else {
        int ans = 0;
        sort (a.rbegin(), a.rend());
        sort (b.rbegin(), b.rend());
        ans = accumulate(a.begin(), a.begin() + m, 0LL) + accumulate(b.begin(), b.begin() + (k - m), 0LL);
        cout << ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}