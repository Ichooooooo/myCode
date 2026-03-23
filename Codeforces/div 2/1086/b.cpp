
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    vector <int> a (n + 1), b;
    b.reserve(n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i != p) b.push_back(a[i]);
    }

    int cr = a[p], ans = 0;
    if (p <= k) {
        ans ++, m -= cr;
    } else {
        sort (a.begin() + 1, a.begin() + p);
        int pay = accumulate(a.begin() + 1, a.begin() + 1 + p - k, 0LL);
        if (pay + cr > m) {
            cout << 0 << '\n';
            return;
        }

        m -= pay + cr;
        ans ++;
    }

    ranges :: sort (b);
    int pay = accumulate(b.begin(), b.begin() + n - k, 0LL);
    ans += m / (pay + cr);
    
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}