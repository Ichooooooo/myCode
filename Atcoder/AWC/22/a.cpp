
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, d, k;
    cin >> n >> d >> k;

    int x, ans = 0;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        if (x - d * k > 0) ans ++;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}