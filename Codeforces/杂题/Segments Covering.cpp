// 全局概率求错了
// 实现的时候如果用map一定要思考这道题能否去重
// 注意数学公式要认真推理 1.怎么用全局值+局部每次值优化时间复杂度 2. 全局值应该放在哪里

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;
const int N = 2e5 + 5;
int dp[N];

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

void ovo() {
    int n, m;
    cin >> n >> m;

    map <int, vector <arr2> > mp;
    int tot = 1;
    for (int i = 0; i < n; i ++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        int x = p * inv (q) % mod;
        int y = (1 + mod - x) % mod;

        // cerr << "xy : " << x << ' ' << y << '\n'; 

        tot = tot * y % mod;

        int z = x * inv (y) % mod;
        mp[r].push_back({l, z});
    }

    dp[0] = 1;

    // cerr << tot << '\n';

    for (auto [r, a] : mp) {
        for (auto [l, x] : a) {
            dp[r] = (dp[r] + dp[l - 1] % mod * x % mod) % mod;
        }
    }

    cout << dp[m] * tot % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}
