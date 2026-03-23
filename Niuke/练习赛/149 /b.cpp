
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;
const int INF = 2e5;

void ovo() {   
    int n, x;
    cin >> n >> x;
    vector <int> a (n + 1), b (n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int mx = a[1];
    int cur  = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        cur = a[i] - sum;
        mx = max (mx, cur);
        sum += (b[i] - a[i]);
    }

    cerr << mx << '\n';

    if (sum >= 0) {
        if (x >= mx) {
            cout << "Infinity" << '\n';
            return;
        }

        for (int i = 1; i <= n; i ++) {
            if (x >= a[i]) {
                x = x + b[i] - a[i];
            } else {
                cout << i - 1 << '\n';
                return;
            }
        }

        cout << n << '\n';

    } else {
        int rd = (x - mx) / abs (sum) + 1;
        int ans = rd * n;
        x = x - rd * abs (sum);

        for (int i = 1; i <= n; i ++) {
            if (x >= a[i]) {
                x = x + b[i] - a[i];
            } else {
                cout << ans + i - 1 << '\n';
                return;
            }
        }

        cout << ans + n << '\n';
    }

    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}