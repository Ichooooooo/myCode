
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;
    cin >> n >> k;
    
    string s;
    int ans = 0;
    while (n --) {
        cin >> s;
        int cnt = ranges :: count (s, '!');
        if (cnt >= k) ans ++;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}