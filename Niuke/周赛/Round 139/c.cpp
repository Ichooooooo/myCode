#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, q;
    cin >> n >> q;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <arr2> b (q);
    for (int i = 0; i < q; i ++) {
        int x, y; cin >> x;
        if (x == 1) {
            cin >> y;
            b[i] = {x, y};
        } else {
            b[i] = {x, 0};
        }
    }

    stack <int> st;
    queue <int> qu;
    int ok1 = 1, ok2 = 1;
    int cnt = 0;
    
    for (int i = 0; i < q; i ++) {
        auto [x, y] = b[i];
        
        if (x == 1) {
            st.push(y);
            qu.push(y);
        } else {
            cnt++;
            int t1 = st.top(); st.pop();
            int t2 = qu.front(); qu.pop();
            
            if (t1 != a[cnt]) {
                ok1 = 0;
            }
            if (t2 != a[cnt]) {
                ok2 = 0;
            }
        }
    }

    if (ok1 && !ok2) {
        cout << "stack" << '\n';
    } else if (!ok1 && ok2) {
        cout << "queue" << '\n';
    } else if (ok1 && ok2) {
        cout << "both" << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}