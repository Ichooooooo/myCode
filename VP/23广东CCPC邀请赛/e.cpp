#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, k;
    cin >> n >> k;
    vector <string> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort (a.begin(), a.end());
    
    vector <string> b (n);
    vector <string> cand; cand.reserve (n);

    auto gets = [&] (string x, string y) -> string {
        string t;
        for (int i = 0; i < min (x.size(), y.size()); i ++) {
            if (x[i] == y[i]) {
                t += x[i];
            } else {
                break;
            }
        }

        return t;
    };

    for (int i = 1; i < n; i++) {
        string s = gets (a[i], a[i - 1]);
        b[i] = s;
        cand.push_back (s);
    }

    sort (cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    auto check = [&] (int mid) -> bool{
        string x = cand[mid];
        int ans = 1;
        for (int i = 1; i < n; i ++) {
            if (b[i] <= x) {
                ans++;
            }
        }

        if (ans >= k) return true;
        else return false;
    };

    int l = 0, r = cand.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check (mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    // for (string & s : b) {
    //     cerr << s << '\n';
    // }
    
    // cerr << l << ' ' << r << '\n';

    if (cand[l].empty()) {
        cout << "EMPTY" << '\n';
    } else {
        cout << cand[l] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}