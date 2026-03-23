#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, m, k;  cin >> n >> m >> k;

    vector <PII> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].first >> a[i].second;
    }

    vector <int> mn (n);
    for (int i = n - 1; i >= 0; i --) {
        if (i == n - 1) mn[i] = a[i].second;
        else mn[i] = min (mn[i + 1], a[i].second);
    }
    
    int ans = -1;
    auto dfs = [&](int x, int fa, int p, int fe, auto self) -> void {
        if (x > n - 1) {
            ans = max (ans, p);
            return;
        }
        
        if (m - fe < mn[x]) {
            ans = max (ans, p);
            return;
        }

        if (x - fa > k) {
            ans = max (ans, p);
            return;
        }

        

        self (x + 1, fa, p, fe, self);

        if (fe + a[x].second <= m) {
            self (x + 1, x, p + a[x].first, fe + a[x].second, self);
        }
    };

    dfs (0, 300, 0, 0, dfs);


    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}