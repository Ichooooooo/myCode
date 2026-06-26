
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    vector <int> mn (n + 1);
    vector <int> mx (n + 1);

    for (int i = 1; i <= n; i ++) {
        mx[i] = i;
        mn[i] = n + 1 - i;
    }

    int bg = 1, ed = 1, ok = 0;
    vector <arr2> cmn;
    for (int i = 1; i <= n - 1; i ++) {
        if ((i == 1 && s[i - 1] == '<') || (i != 1 && (s[i - 2] == '>' && s[i - 1] == '<'))) {
            bg = i;
            ok = 1;
        } 

        if (ok && s[i - 1] == '>') {
            ed = i;
            // cerr << "qujian : " << bg << ' ' << ed << '\n';
            cmn.push_back ({bg, ed});
            ok = 0;
        }
    }

    if (ok) {
        cmn.push_back ({bg, n});
    }

    for (auto [x, y] : cmn) {
        for (int i = x; i <= (x + y) / 2; i ++) {
            int t = mn[x + y - i];
            mn[x + y - i] = mn[i];
            mn[i] = t;
        }
    }

    bg = 1, ed = 1, ok = 0;
    vector <arr2> cmx;
    for (int i = 1; i <= n; i ++) {
        if ((i == 1 && s[i - 1] == '>') || (i != 1 && (s[i - 2] == '<' && s[i - 1] == '>'))) {
            bg = i;
            ok = 1;
        } 

        if (ok && s[i - 1] == '<') {
            ed = i;
            // cerr << "qujian2 : " << bg << ' ' << ed << '\n';
            cmx.push_back ({bg, ed});
            ok = 0;
        }
    }

    if (ok) {
        cmx.push_back ({bg, n});
    }

    for (auto [x, y] : cmx) {
        for (int i = x; i <= (x + y) / 2; i ++) {
            int t = mx[x + y - i];
            mx[x + y - i] = mx[i];
            mx[i] = t;
        }
    }   

    for (int i = 1; i <= n; i ++) {
        cout << mn[i] << " \n"[i == n];
    }

    for (int i = 1; i <= n; i ++) {
        cout << mx[i] << " \n"[i == n];
    }

    // cerr << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}