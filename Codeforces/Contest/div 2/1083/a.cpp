
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;
    cin >> n;
    vector <int> a (n);
    map <int, int> mp;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    int p = 0;
    while (a[p] == n - p && p <= n - 1) p ++;

    if (p == n) {
        for (int i = 0; i < n; i ++) cout << a[i] << " \n"[i == n - 1];
    } else {
        swap (a[p], a[mp[n - p]]);
        for (int i = 0; i < n; i ++) cout << a[i] << " \n"[i == n - 1];
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}