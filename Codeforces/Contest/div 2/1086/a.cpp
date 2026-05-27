
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n; cin >> n;
    map <int, int> mp;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            int x; cin >> x;
            mp[x] ++;
        }
    }

    int mx = -1;
    for (auto [x, y] : mp) mx = max (mx, y);
    if (mx > n * (n - 1)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}