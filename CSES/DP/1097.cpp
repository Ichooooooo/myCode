// 1. 注意题目条件, 当总和一定的时候, 两人的分数就是零和博弈, 可以用差值表示最优解
// 2. 注意找一个dp顺畅的定义
// 3. 当题目一个dp转移简单的时候, 可以直接用赋值来避免初始化, 边界灵活处理

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }

    vector <vector <int> > dp (n + 2, vector <int> (n + 2));

    for (int len = 1; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;

            int t = n - len;
            if (t % 2 == 0) {
                dp[l][r] = max(a[l] + dp[l + 1][r],
                            a[r] + dp[l][r - 1]);
            } else {
                dp[l][r] = min(-a[l] + dp[l + 1][r],
                            -a[r] + dp[l][r - 1]);              
            }
        }
    }

    cout << (sum + dp[1][n]) / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}