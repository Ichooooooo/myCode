
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;
    cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    map <int, int, greater <int>> mp;

    for (int i = 1; i <= n; i ++) {
        int t = (i ^ (a[i - 1]));
        mp[t] ++;
    }

    int mx = 0;
    for (auto [x, y] : mp) mx = max (mx, y);
    cout << n - mx << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}