#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> a (n + 1); for (int i = 1; i <= n; i ++) cin >> a[i];

    vector <int> b (m + 1); for (int i = 1; i <= m; i ++) cin >> b[i];
    ranges :: sort (b | views :: drop(1));

    string s; cin >> s;
    map <int, vector<int>> mp;
    for (int i = 1; i <= n; i ++) {
        int x = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        if (x <= m) {
            int d1 = b[x] - a[i];
            mp[d1].push_back(i);
        }
        if (x - 1 > 0) {
            int d2 = b[x - 1] - a[i];
            mp[d2].push_back(i);
        }
    }

    vector <int> vis (n + 1, 1LL);
    int dis = 0, cnt = 0;
    for (char & i : s) {
        if (i == 'R') dis ++;
        else dis --;

        auto it = mp.find(dis);
        if (it != mp.end()) {
            for (auto v : mp[dis]) {
                if (vis[v]) {
                    cnt ++;
                    vis[v] = 0;
                }
            }
            mp[dis].clear();
        }
        cout << n - cnt << ' ';
    }
    cout << endl;
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