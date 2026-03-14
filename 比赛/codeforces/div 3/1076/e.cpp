#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <int> a (n + 1);
    set <int> st;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i]; st.insert(a[i]);
    }

    vector <int> dp (n + 1, LLONG_MAX);
    for (int i : st) {
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i ++) {
        if (dp[i] == LLONG_MAX) continue;
        for (int j : st) {
            if (j * i > n) break;
            dp[j * i] = min (dp[j * i], dp[i] + 1);
        }
    }   

    for (int i = 1; i <= n; i ++) {
        if (dp[i] == LLONG_MAX) {
            cout << -1 << " \n"[i == n];
        } else {
            cout << dp[i] << " \n"[i == n];
        }
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