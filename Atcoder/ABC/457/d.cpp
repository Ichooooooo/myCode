
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 5e18;

void ovo() {
    int n;
    cin >> n;
    vector <int> a (n + 1);
    int mn = INF;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mn = min (mn, a[i]);
    }

    int k; cin >> k;

    auto check = [&] (int mid) -> int {
        int cnt = 0;

        for (int i = 1; i <= n; i ++) {
            if (a[i] < mid) {
                cnt += (mid - a[i] + i - 1) / i;
            }

            if (cnt > INF)  return INF;
        } 

        return cnt;
    };

    int l = mn, r = INF;

    cerr << "k : " << k << '\n';
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        int x = check (mid);
        cerr << "x : " << x << '\n';

        if (x > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        
        cerr << "mid : " << mid << ' ' << l << ' ' << r << ' ' << x << '\n';
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}