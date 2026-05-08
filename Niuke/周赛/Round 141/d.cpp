
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; 
    cin >> n;
    vector <int> a (n);

    vector <int> vis (35);
    map <int, int> mp;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] < 35) {
            vis[a[i]]++;
        }

        mp[a[i]]++;
    }

    if (mp[1] > 1) {
        cout << "YES" << '\n';
        return;
    }


    for (int i = 0; i < n; i ++) {
        for (int j = 1; j < 35; j ++) {
            if (pow (a[i], j) > 1e9) break;
            if (vis[j] == 0) continue;

            int t = pow (a[i], j);

            if (mp.find(t) != mp.end()) {
                // cerr << i << ' ' << j << a[i]  << ' ' << t << '\n';
                if (t == j && mp[t] == 1) continue;
                if (t == a[i] && mp[t] == 1) continue;               
                cout << "YES" << '\n';
                return; 
            }
        }
    }

    cout << "NO" << '\n';


}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}