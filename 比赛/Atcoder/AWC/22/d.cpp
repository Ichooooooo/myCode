
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;
    cin >> n >> k;
    vector <int> a (n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector <int> diff(n + 1);

    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        now ^= diff[i];
        if ((a[i] ^ now) == 1 && i + k - 1 >= n) {
            cout << -1 << '\n';
            return;
        }

        if ((a[i] ^ now) == 1) {
            now ^= 1;
            diff[i + k] ^= 1;
            ans ++;
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