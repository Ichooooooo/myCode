
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, k;
    cin >> n >> m >> k;

    int x, cnt = 0;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        int ch = max (0LL, k - x);
        cnt += ch;
    }

    if (m < cnt) {
        cout << -1 << '\n';
    } else {
        cout << cnt << '\n'; 
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}