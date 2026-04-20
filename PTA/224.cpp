
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    while (n --) {
        int opt; string s1, s2;
        cin >> opt;
        if (opt == 1) {
            cin >> s1;
            auto pos = s.find(s1);
            if (pos == string :: npos) {
                cout << -1 << '\n';
            } else {
                cout << pos << '\n'; 
            }
        } else if (opt == 2) {
            cin >> s1 >> s2;
            auto pos = s.find(s1);
            int sz = s1.size();

            if (pos == string :: npos) {
                cout << s << '\n';
            } else {
                s = s.replace (pos, sz, s2);
                cout << s << '\n';
            }
        } else if (opt == 3) {
            char c1, c2;
            cin >> c1 >> c2 >> s1;

            string t;
            t += c1;
            t += c2;
            
            size_t pos;
            int m = s1.size(), now = 0;
            while ((pos = s.find(t, now)) != string:: npos) {
                s.replace (pos + 1, 0, s1);
                now = pos + 1 + m;
            }

            cout << s << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}