
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;
    cin >> n;
    
    int now = 0;
    int a, b;
    for (int i = 0; i < n; i ++) {
        if (i == n - 1) {
            cin >> a;
            now += a;
        } else {
            cin >> a >> b;
            now += a;
            now -= min (now, b);
        }
    }

    cout << now << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}