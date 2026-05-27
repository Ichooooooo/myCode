
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    if (n & 1) {
        cout << n - 1 << ' ';
        for (int i = 2; i <= n - 1; i ++) cout << (1 ^ i) << ' ';
        cout << 1 << '\n';
    } else {
        vector <int> a (n + 1), vis (n + 1);
        a[1] = n; a[n] = 1;
        for (int i = 2; i <= n - 1; i ++) a[i] = (i ^ 1);

        int ok = 0;
        for (int i = 2; i <= n - 1; i ++) {
            int tar = (n ^ i);
            if (tar <= n && !vis[tar]) {
                ok = 1;
                int t = a[1];
                a[1] = a[i];
                a[i] = t;
                break;
            } else {
                vis[a[i]] = 1;
            }
        }

        if (!ok) {
            cout << -1 << '\n';
        } else {
            for (int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}