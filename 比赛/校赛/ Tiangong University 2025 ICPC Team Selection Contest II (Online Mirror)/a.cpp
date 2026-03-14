
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, x;  cin >> n >> x;
    vector <int> a(n);
    for (int & i : a) cin >> i;

    int sum = accumulate(a.begin(), a.end(), 0LL);

    vector <int> dp (sum + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i ++) {
        for (int j = sum; j >= a[i]; j --) {
            dp[j] |= dp[j - a[i]];
        }
    }

    int ans = LLONG_MAX;
    for (int i = 0; i <= sum; i ++) {
        if (dp[i]) {
            ans = min (ans, abs(sum + x - 2 * i));
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}