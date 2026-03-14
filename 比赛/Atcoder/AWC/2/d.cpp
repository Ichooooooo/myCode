#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;  cin >> n >> m;
    vector <int> a (n), b (m);
    
    for (int & i : a) cin >> i;
    for (int & j : b) cin >> j;
    ranges :: sort (a);
    ranges :: sort (b);

    int p = 0, cnt = 0;
    for (int i = 0; i < n; i ++) {
        int t = lower_bound(b.begin() + p, b.end(), a[i]) - b.begin();
        if (t > m - 1) break;
        cnt ++;
        p = t + 1;
        // cout << p << ' ';
        if (p > m - 1) break;
    }

    cout << cnt << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}