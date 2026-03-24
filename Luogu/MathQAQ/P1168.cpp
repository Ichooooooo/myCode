
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    priority_queue <int> L;
    priority_queue <int, vector <int>, greater <int>> R;
    
    for (int i = 1; i <= n; i ++) {
        if (L.empty() || a[i] <= L.top()) {
            L.push(a[i]);
        } else {
            R.push(a[i]);
        }

        if (L.size() > R.size() + 1) {
            R.push(L.top());
            L.pop();
        }

        if (R.size() > L.size()) {
            L.push(R.top());
            R.pop();
        }

        if (i & 1) {
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