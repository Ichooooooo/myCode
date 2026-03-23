
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    
    vector <int> a (n + 1), pre (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int s, l, r;
    for (int i = 1; i <= m; i ++) {
        cin >> s >> l >> r;
        cout << s + pre[r] - pre[l - 1] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}