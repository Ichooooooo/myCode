
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int m, n, z;
    cin >> m >> n >> z;
    
    z = z % (m + n);
    if (z > 0 && z <= m) cout << 0;
    else cout << 1;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}