
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s; cin >> s;
    vector <arr2> a (26);
    int n = s.size();

    for (int i = 0; i < n; i ++) {
        a[s[i] - 'a'][0]++;
    }

    int mx = 0;
    for (int i = 0; i < 26; i ++) {
        mx = max (mx, a[i][0]);
    }

    for (int i = 0; i < 26; i ++) {
        a[i][1] = i; 

        // cerr << "i : " << i << ' ' << a[i][0] << ' ' << a[i][1] << '\n';
    }

    if (mx - 1 > n - mx) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';

    sort (a.rbegin(), a.rend());
    
    // for (auto [x, y] : a) {
    //     // cerr << "a : " << x << ' ' << char (y + 'a') << '\n';
    // }

    vector <char> ans (n);
    int pos = 0;
    for (int i = 0; i < n; i += 2) {
        while (a[pos][0] == 0) pos++;
        int now = a[pos][1];
        ans[i] = now + 'a';

        // cerr << "pos : " << pos << ' ' << now << ' ' << (char) (now + 'a') << ' ' << a[pos][0] << '\n';
        a[pos][0]--;
    }

    for (int i = 1; i < n; i += 2) {
        while (a[pos][0] == 0) pos++;
        int now = a[pos][1];
        ans[i] = now + 'a';
        a[pos][0]--;
    }    

    for (int i = 0; i < n; i ++) {
        cout << ans[i];
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}