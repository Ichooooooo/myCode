
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    int k = a[m - 1], ans = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] < k) ans ++;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}