
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m; 
    cin >> n >> m;

    vector <int> a (n), pos (n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;

        // cerr << "i : " << a[i] << ' ' << pos[a[i]] << '\n';
    }

    int now = 1;
    for (int i = 1; i <= n - 1; i ++) {
        now += (pos[i] > pos[i + 1]);
    }

    // cerr << now << '\n';

    while (m --) {
        int x, y;
        cin >> x >> y;

        x--, y--;
        int n1 = a[x], n2 = a[y];

        // cerr << n1 << ' ' << n2 << '\n';
        if (n1 - 1 >= 1) now -= (pos[n1 - 1] > pos[n1]);
        if (n1 + 1 <= n) now -= (pos[n1] > pos[n1 + 1]);
        if (n2 - 1 >= 1 && n2 - 1 != n1) now -= (pos[n2 - 1] > pos[n2]);
        if (n2 + 1 <= n && n2 + 1 != n1) now -= (pos[n2] > pos[n2 + 1]);

        // cerr << "pas : " << now << '\n';

        swap (a[x], a[y]);
        swap (pos[n1], pos[n2]);
        if (n1 - 1 >= 1) now += (pos[n1 - 1] > pos[n1]);
        if (n1 + 1 <= n) now += (pos[n1] > pos[n1 + 1]);
        if (n2 - 1 >= 1 && n2 - 1 != n1) now += (pos[n2 - 1] > pos[n2]);
        if (n2 + 1 <= n && n2 + 1 != n1) now += (pos[n2] > pos[n2 + 1]);      

        // cerr << "now : " << now << '\n';
        cout << now << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}