
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, x;
    cin >> n >> x;
    
    int p = 0, tar = 0;
    for (p = 0; p < n - 1; p ++) {
        if ((p | x) == x) {
            cout << p << ' ';
            tar = (tar | p);
        } else break;
    }
    if (p == n - 1) {
        if ((tar | p) == x) cout << p << ' ';
        else {
            cout << x << ' ';
        }
    } else {
        for (int i = p; i < n; i ++) cout << x << ' ';
    }
    
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}