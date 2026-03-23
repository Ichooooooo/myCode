
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> bs(n);
    for (int i = 0; i < n; i ++) {
        bs[i] = (1 << i);
    }

    int nm = (1 << n);
    vector <int> vis (nm, 1);

    cout << 0 << ' ';
    vis[0] = 0;
    int cur = 0, ps = 0;
    for (int i = 1; i < nm; i ++) {
        int p = 0;
        cur = ps ^ bs[p];
        while (!vis[cur]) {
            p ++;
            cur = ps ^ bs[p];
        }
        cout << cur << ' ';
        vis[cur] = 0;
        ps = cur;
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}