
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> ind (n + 1);
    vector <vector <int> > g (n + 1);
    for (int i = 1; i <= n; i ++) {
        int x;
        while (cin >> x) {
            if (x == 0) break;
            g[i].push_back (x);
            ind[x] ++;
        }
    }

    queue <int> qu;
    vector <int> ans; ans.reserve(n + 5);
    for (int i = 1; i <= n; i ++) {
        if (ind[i] == 0) {
            qu.push(i);
            ans.push_back(i);
        }
    }

    while (qu.size()) {
        int t = qu.front(); qu.pop();

        for (int x : g[t]) {
            if ((--ind[x]) == 0) {
                qu.push(x);
                ans.push_back(x);
            }
        }
    }


    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}