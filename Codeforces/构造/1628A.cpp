#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> mex (n + 1);
    vector <int> vis (n + 1);
    int now = 0;
    for (int i = n; i >= 1; i --) {
        vis[a[i]]++;
        while (vis[now]) now++;
        mex[i] = now;
    }

    vector <int> b; b.reserve (n);

    vector <int> tvis;
    int pas = 1;
    while (pas <= n) {
        int m = mex[pas];
        tvis.assign(m + 1, 0);
        
        int tnow = 0;
        for (int i = pas; i <= n; i ++) {
            tvis[a[i]]++;
            while (tvis[tnow]) tnow++;
            if (tnow == m) {
                pas = i + 1;
                b.push_back(m);
                break;
            }
        }
    }

    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); i ++) {
        cout << b[i] << " \n"[i == b.size() - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}