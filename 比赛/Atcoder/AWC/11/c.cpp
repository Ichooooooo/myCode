
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;
    cin >> n >> k;

    vector <int> a (70);
    for (int bit = 0; bit <= 69; bit ++) {
        a[bit] = (k & (1LL << bit));
    }

    int ans = 0;
    vector <int> rol (70);
    int t;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        int ok = 1;
        for (int bit = 0; bit <= 69; bit ++) {
            int x = (t & (1LL << bit));
            if ((a[bit] | x) != a[bit]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans ++;
            for (int bit = 0; bit <= 69; bit ++) {
                int x = (t & (1LL << bit));
                rol[bit] = (rol[bit] | x);
            }
        }
    }   

    if (rol != a || (k == 0 && ans == 0)) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}