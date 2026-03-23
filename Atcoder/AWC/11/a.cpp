
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;

    if (s > t) swap(s, t);
    vector <pair<int, int>> a (m);

    int ans = 0;
    for (auto [x, y] : a) {
        cin >> x >> y;
        if (x >= s && x <= t) {
            ans += y;
        }
    }

    cout << ans << '\n';
    

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}