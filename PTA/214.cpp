
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1e5;

void ovo() {
    int n, m; cin >> n >> m;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    while (m --) {
        int opt; cin >> opt;

        if (opt == 1) {
            int l1, l2;
            cin >> l1;
            vector <int> pp (l1);
            for (int i = 0; i < l1; i ++) {
                cin >> pp[i];
            }

            int pos = 0, rt = -1;
            // cerr << "pp : " << pp[pos] << '\n';

            for (int i = 0; i < a.size(); i ++) {
                // cerr << "a : " << a[i] << '\n';

                if (a[i] == pp[pos]) {
                    // cerr << "i : " << i << "nope \n";
                    pos++;
                } else {
                    // cerr << "i : " << i << "nope \n";
                    pos = 0;
                }

                // cerr << "i : " << i << ' ' << a[i] << '\n';

                if (pos == l1) {
                    rt = i - l1;
                    break;
                    // cerr << "rt : " << rt << '\n';
                }
            }

            vector <int> b; b.reserve(N);

            int ok = 1;
            if (rt == -1) {
                // cerr << "??" << '\n';
                ok = 0;
            }

            for (int i = 0; i <= rt; i ++) {
                b.push_back(a[i]);
            }

            cin >> l2;
            for (int i = 0; i < l2; i ++) {
                int x; cin >> x;
                b.push_back(x);
            }

            if (!ok) {
                continue;
            }

            for (int i = rt + l1 + 1; i < a.size(); i ++) {
                b.push_back(a[i]);
            }

            a = b;
        } else if (opt == 2) {
            vector <int> b; b.reserve(N);
            b.push_back(a[0]);

            // for (int & i : b) cerr << i << '\n';
            for (int i = 1; i < a.size(); i ++) {
                if ((a[i] + a[i - 1]) % 2 == 0) {
                    // cerr << "i : " << i << ' ' << (a[i] + a[i - 1]) / 2 << '\n';
                    b.push_back((a[i] + a[i - 1]) / 2);
                    b.push_back(a[i]);
                } else {
                    b.push_back(a[i]);
                }
            }

            // for (int & i : b) cerr << i << '\n';
            a = b;
        } else if (opt == 3) {
            int l, r; cin >> l >> r;

            l--; r--;
            for (int i = l; i <= (l + r) / 2; i ++) {
                int t = a[i];
                int p = a[l + r - i];

                a[l + r - i] = t;
                a[i] = p;
            }
        }
    }

    for (int i = 0; i < a.size(); i ++) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}