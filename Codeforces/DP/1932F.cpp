
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e10;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <arr2> a (m);

    vector <int> pre (n + 5);
    for (int i = 0; i < m; i ++) {
        cin >> a[i][0] >> a[i][1];
        pre[a[i][0]]++;
        pre[a[i][1] + 1]--;
    }

    for (int i = 1; i <= n; i ++) {
        pre[i] += pre[i - 1];
    }

    sort (a.begin(), a.end());

    vector <int> mnl (n + 1), mxr (n + 1);
    
    int cl = a[0][0], cr = a[0][1];
    for (int i = cl; i <= cr; i ++) {
        mnl[i] = cl;
    }

    for (int i = 1; i < m; i ++) {
        if (a[i][1] <= cr) continue;
        
        cl = max (cr + 1, a[i][0]);
        cr = a[i][1];

        for (int j = cl; j <= cr; j ++) {
            mnl[j] = a[i][0];
        }
    }

    sort (a.begin(), a.end(), [&] (auto  v, auto  u) {
        if (v[1] != u[1])
        return v[1] > u[1];
        else 
        return v[0] > u[0]; 
    });

    cl = a[0][0], cr = a[0][1];
    for (int i = cl; i <= cr; i ++) {
        mxr[i] = cr;
    }

    for (int i = 1; i < m; i ++) {
        if (a[i][0] >= cl) continue;
        
        cr = min (cl - 1, a[i][1]);
        cl = a[i][0];

        for (int j = cl; j <= cr; j ++) {
            mxr[j] = a[i][1];
        }
    }

    vector <int> dp (n + 1);
    for (int i = 1; i <= n; i ++) {
        dp[i] = max (dp[i], dp[i - 1]);
        if (mnl[i] == 0) continue;

        dp[mxr[i]] = max (dp[mxr[i]], dp[i - 1] + pre[i]);
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}