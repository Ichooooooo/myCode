
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = k;
    int x, y;
    vector <int> vis (n + 1);
    for (int i = 1; i <= k; i ++) vis[i] = 1;
    while (m --) {
        cin >> x >> y;
        if ((vis[x] ^ vis[y]) == 0) continue;
        else if (vis[x]) {
            cnt ++;
            vis[y] = 1;
        } else {
            cnt ++;
            vis[x] = 1;
        }
    }

    cout << cnt << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}