## C

[题目 - C - Codeforces --- Problem - C - Codeforces](https://codeforces.com/contest/2178/problem/C)

##### 基本考点：前缀和，区间段最大值

##### 基本思路：

从全局来看，便到最后只会剩下一个数字a[i]，我们贪心的时候尽量想加上正数，减去负数，那么除了第一个数我们只能加以外，a[i]左边的其他的数我们总有办法能加正减负(随便取一个正负交加的数组)，而把前面的数都取完了，a[i]后面的就只能减去(第一位是选择的a[i])

```cpp
void solve(){   
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pz(n), pf(n), pre(n);

    for (ll i = 0; i < n; i ++) {
        cin >> a[i];
        if (i == 0) {
            pre[i] = a[i];
            pz[i] = a[i];
            pf[i] = 0;
        } else {
            pre[i] = pre[i - 1] + a[i];
            pz[i] = pz[i - 1]; pf[i] = pf[i - 1];
            if(a[i] > 0) pz[i] += a[i];
            else pf[i] += a[i];
        }
    }

    // cout << pz[0] << ' ' << ' ' << pf[0] << ' ' << pre[0] << ' ' << pre[1] << endl;
    ll cur, ans = -1e16;
    for (int i = 0; i < n; i ++) {
        if (i > 0) cur = pz[i - 1] - pf[i - 1] - (pre[n - 1] - pre[i]);
        else cur = -1 * (pre[n - 1] - pre[i]);
        // cout << i << ' ' <<  pz[i - 1] - pf[i - 1] << ' ' << (pre[n - 1] - pre[i]) << ' ' << cur << endl;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
```

##### 错误点：

1. 没有注意数据范围用int

2. 没有注意因为有加有减，所以结果可能为负，而错误设置ans的初始值

3. 错误理解了区间段最大值求，维护左端点max最大，然后枚举和每个右端点结合，用cur和ans维护，求解最大