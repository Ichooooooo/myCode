
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;
    cin >> n;
    vector <int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
        a[i] = 2 * i - a[i];
    }

    vector <int> dp (n + 1);

    for (int i = 1; i <= n; i ++) {
        dp[i] = max (dp[i - 1] + a[i], a[i]);
    }

    cout << sum + ranges :: max (dp) << '\n';

    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}