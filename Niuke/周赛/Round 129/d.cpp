#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string s;  cin >> s;
    int n = s.size();
    
    int ans = 1, add = 0;
    for (int i = 1; i < n - 1; i ++) {
        if (s[i] == s[i - 1]) add ++;
        if (s[i] == s[i + 1]) ans += (i - add);
        else ans += add;
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}