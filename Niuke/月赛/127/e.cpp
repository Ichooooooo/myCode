#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 2 * 1e5 + 10;

int fa[N], siz[N], dep[N];
vector <int> g[N];

void solve(){   
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        g[i].clear();
    }

    int a, b;
    for (int i = 1; i < n; i ++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto dfs = [&] (int u, int f, auto self) -> void {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        siz[u] = 1;
        
        for (auto v : g[u]) {
            if (v == f) continue;
            self(v, u, self);
            siz[u] += siz[v];
        }
    };

    dfs(1, 0, dfs);

    int dist = 0, disp = 0, m = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        dist = (dist + (siz[i] * (n - siz[i]) % mod)) % mod; //累加也要取模
    }
    
    for (int i = 1; i <= n; i ++) {
        disp = (disp + (dep[i] * (dep[i] - 1) ) / 2 % mod) % mod;
    }

    for (int i = 1; i <= n; i ++) {
        m = (m + (siz[i] - 1)) % mod;
    }

    ans = (dist - disp + m) % mod;
    ans = (ans + mod) % mod; //防止z负数
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}