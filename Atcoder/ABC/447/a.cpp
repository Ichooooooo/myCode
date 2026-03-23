
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m; cin >> n >> m;
    int w = n & 1;
    int q = n / 2 + w;
    
    if (q >= m) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}