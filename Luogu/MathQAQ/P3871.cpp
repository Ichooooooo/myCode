
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        if (L.empty() || x <= L.top()) {
            L.push(x);
        } else {
            R.push(x);
        }

        if (L.size() > R.size() + 1) {
            R.push(L.top());
            L.pop();
        }

        if (R.size() > L.size()) {
            L.push(R.top());
            R.pop();
        }
    }

    int q; cin >> q;
    while (q --) {
        string s; cin >> s;
        if (s == "add") {
            int x; cin >> x;
            if (L.empty() || x <= L.top()) {
                L.push(x);
            } else {
                R.push(x);
            }

            if (L.size() > R.size() + 1) {
                R.push(L.top());
                L.pop();
            }

            if (R.size() > L.size()) {
                L.push(R.top());
                R.pop();
            }
        } else {
            cout << L.top() << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}