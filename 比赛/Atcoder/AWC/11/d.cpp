
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, q;
    cin >> n >> q;
    vector <int> v (n + 1), p (n + 1);
    p[1] = 0;
    for (int i = 1; i <= n; i ++) cin >> v[i];
    for (int i = 2; i <= n; i ++) cin >> p[i];

    vector <int> cc (n + 1);

    for (int i = 1; i <= n; i ++) {
        cc[i] = cc[p[i]] + v[i];
    }

    int t;
    while (q -- ) {
        cin >> t;
        cout << cc[t] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}