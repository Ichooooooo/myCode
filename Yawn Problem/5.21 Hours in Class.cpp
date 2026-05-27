
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int q; cin >> q;

    map <int, int> mp;
    set <int> st;

    int opt, x;

    auto add = [&] (int p, int x) -> void {
        if (mp[p] >= 30) return;

        mp[p] = min (mp[p] + x, 30LL);
        if (mp[p] < 30) st.insert (p);
        else st.erase (p); 
    }; 

    while (q --) {
        cin >> opt >> x;
        if (opt == 1) {
            int cnt = 0;

            while (x % 2 == 0) {
                cnt++;
                x /= 2;
            }

            if (cnt) {
                add (2, cnt);
                // mp[2] = min (mp[2] + cnt, 30LL);
            }

            for (int i = 3; i * i <= x; i += 2) {
                int cn = 0;
                while (x % i == 0) {
                    cn++;
                    x /= i;
                }
                if (cn) {
                    add (i, cn);
                    // mp[i] = min (mp[i] + cn, 30LL);
                }
            }

            if (x > 1) {
                add (x, 1);
                // mp[x] = min (mp[x] + 1, 30LL);
            }
        } else if (opt == 2) {

            vector <int> del;
            for (auto & i : st) {
                mp[i] = min(mp[i] * x, 30LL);
                if (mp[i] >= 30) {
                    del.push_back (i);
                }
            }

            for (auto x : del) {
                st.erase (x);
            }

        } else {
            int cnt = 0;
            while (x % 2 == 0) {
                cnt++;
                x /= 2;
            }

            if (cnt) {
                if (mp.find(2) == mp.end() || mp[2] < cnt) {
                    cout << "No" << '\n';
                    continue;
                }
            }

            int ok = 1;
            for (int i = 3; i * i <= x; i += 2) {
                int cn = 0;
                while (x % i == 0) {
                    cn++;
                    x /= i;
                }

                if (cn) {
                    if (mp.find(i) == mp.end() || mp[i] < cn) {
                        ok = 0;
                        break;
                    }
                }
            }      

            if (!ok) {
                cout << "No" << '\n';
                continue;
            }
            
            if (x > 1) {
                if (mp.find(x) == mp.end()|| mp[x] < 1) {
                    cout << "No" << '\n';
                    continue;
                }
            }

            cout << "Yes" << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}