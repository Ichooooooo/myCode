
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
        cout << n << ' ';
        for (int i = 2; i <= n - 1; i ++) cout << (1 ^ i) << ' ';
        cout << 1 << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}