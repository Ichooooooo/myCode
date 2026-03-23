
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){       
    int n; cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    int ll = 1e18, rr = 1e18, ans = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] <= ll || a[i] > rr + 1) {
            ans ++;
            ll = rr = a[i];
        } else {
            rr = a[i];
        }
    }

    cout << ans << '\n';
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}