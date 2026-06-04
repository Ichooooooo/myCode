
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> f (n + 1);
    vector <int> vis (n + 1);

    vector <int> song; song.reserve (n + 5);
    int cnt = 0;

    for (int i = 1; i <= n; i ++) {
        cin >> f[i];
        vis[f[i]] = 1;

        if (f[i] == 0) {
            // cerr << "s : " << i << '\n';
            song.push_back (i);
            cnt++;
        }
    }

    vector <int> shou; shou.reserve (n + 5);

    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            // cerr << "s : " << i << '\n';
            shou.push_back (i);
        }
    }

    if (cnt == 2) {
        // // cerr << "cnt2" << '\n';
        if (shou[0] != song[0] && shou[1] != song[1]) {
            f[song[0]] = shou[0];
            f[song[1]] = shou[1];
        } else {
            f[song[0]] = shou[1];
            f[song[1]] = shou[0];          
        }
    } else {
        
        vector <int> pd; pd.reserve (n + 5);
        for (int i = 0; i < cnt; i ++) {
            f[song[i]] = shou[i];
            if (song[i] == shou[i]) {
                pd.push_back (song[i]);
            }
        }

        int sz = pd.size();
        if (sz == 1) {
            int x = pd[0];
            for (int i = 0; i < cnt; i ++) {
                if (song[i] != x) {
                    swap (f[song[i]], f[x]);
                    break;
                }
            }
        } else {
            for (int i = 0; i < sz; i ++) {
                f[pd[i]] = pd[(i + 1) % sz];
            }
        }
        

    }

    for (int i = 1; i <= n; i ++) {
        cout << f[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}