
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a (n + 1);

    int k;
    set <array<int, 2>> st;
    map <int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> k;
        a[i].reserve(k); int t;
        for (int i = 0; i < k; i ++) {
            cin >> t; a[i].push_back(t);
            mp[t] ++;
        }
        st.insert({k, i});
    }

    vector <int> vis (110);
    int ans = 0;
    for (auto & [x, y] : st) {
        // cout << x << ' ' << y << '\n';

        sort (a[y].begin(), a[y].end(), [&](const int &i, const int &j) {
            if (mp[i] != mp[j]) return mp[i] < mp[j];
            else return vis[i] < vis[j];
        });
        for (auto i : a[y]) cout << i << '\n';
        cout << a[y][0] << '\n';
        // if (vis[] == 0) {
        //     ans ++;
        //     vis[a[y][0]] == 1;
        // }
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}