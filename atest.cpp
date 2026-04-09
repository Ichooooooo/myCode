#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using i128 = __int128;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<arr2> b;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        b.push_back({r, l});
    }
    sort(b.begin(), b.end());

    vector<int> pre(n + 5);
    int l = 0;
    for (int i = 0; i < m; i++) {
        l = max(l, b[i][1]);
        pre[b[i][0] + 1] = l;
    }
    pre[1] = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (!pre[i]) pre[i] = pre[i - 1]; 
    }

    vector<int> dp(n + 5, 1e16);
    dp[0] = 0;
    deque<arr2> q;
    q.push_back({dp[0], 0});

    for (int i = 1; i <= n + 1; i++) {
        while (q.size() && q.front()[1] < pre[i]) q.pop_front();

        if (q.size()) {
            dp[i] = q.front()[0] + a[i];
        }
        
        while (q.size() && q.back()[0] >= dp[i]) {
            q.pop_back();
        }
        q.push_back({dp[i], i});
    }

    cout << dp[n + 1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}