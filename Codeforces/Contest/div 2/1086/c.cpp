
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n; cin >> n;
    vector <int> c (n), p (n);
    for (int i = 0; i < n; i ++) {
        cin >> c[i] >> p[i];
    }

    double ans = 0;
    for (int i = n - 1; i >= 0; i --) {
        double an = c[i] + (1 - p[i] / 100.0) * ans;
        if (ans < an) ans = an;
    }

    cout << fixed << setprecision(12) << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}