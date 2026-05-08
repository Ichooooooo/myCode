
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);

    vector <vector <int> > cnt (11, vector <int> (11));
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector <int> seen (11);
    for (int i = 0; i < n; i ++) {
        for (int j = 1; j <= 10; j ++) {
            if (j == a[i]) continue;
            cnt[j][a[i]] += seen[j]; 
        }

        seen[a[i]]++;
    }

    vector <int> p (11);
    iota (p.begin() + 1, p.end(), 1LL);

    int mn = -1;
    do {
        int ans = 0;
        for (int i = 1; i <= 9; i ++) {
            for (int j = i + 1; j <= 10; j ++) {
                ans += cnt[p[j]][p[i]];
            }
        }

        if (mn == -1) mn = ans;
        else mn = min (mn, ans);

    } while (next_permutation(p.begin() + 1, p.end()));

    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}