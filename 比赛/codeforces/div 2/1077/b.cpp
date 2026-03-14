#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    string s;  cin >> s;
    
    if (s.find('1') == string :: npos) {
        cout << (n + 2) / 3 << endl;
    } else {
        int ok = 0, l = 0, ans = 0;
        if (s[0] == '1') {ok = 1;  ans ++;}
        for (int i = 1; i < n; i ++) {
            if (s[i] == '1') ans ++;
            bool x = (s[i - 1] == '0');
            bool y = (s[i] == '1');
            if (x && y) {
                // cout << l << ' ' << i << ' ';
                if (ok) {
                    if (i - l - 2 > 0)
                    ans += (i - l - 2 + 2) /3; 
                } else {
                    if (i - l - 1 > 0)
                    ans += (i - l - 1 + 2) / 3;
                }
                // cout << ans << endl;
                ok = 0;
            } else if (!x && !y) {
                l = i; ok = 1;
            }
        }

        if (ok) ans += (n - l - 1 + 2) / 3;

        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}