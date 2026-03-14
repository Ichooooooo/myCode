#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 1e9 + 7;
const double eps = 1e-10;

int qpow (int a, int b, int m)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return (qpow (x, mod - 2LL, mod));
}

void solve(){   
    int n, m;  cin >> n;
    int u, v; m = n - 1;
    vector <vector <int>> tr(n + 1);
    while (m --) {
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }

    int ans = 0;
    auto dfs = [&] (int dep, int u, int fa, int ps, auto self) -> void{
        cout << dep << ' ' << u << ' ' << ps << endl;
        ps = ps * tr[u].size() % mod;
        
        for (auto v : tr[u]) {
            if (v == fa) ans = (ans + dep * inv(ps) % mod) % mod;
            self (dep + 1, v, u, ps, self);
        }

        return;
    };

    dfs (1, 1, 0, tr[1].size(), dfs);

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}