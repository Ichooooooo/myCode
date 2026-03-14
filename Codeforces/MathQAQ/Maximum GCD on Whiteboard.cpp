
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;
    cin >> n >> k;

    map <int, int> mp;
    vector <int> pre (n + 1);
    int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        mp[x] ++;
    }

    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + mp[i];
    }

    int ans = 1;
    for (int i = 1; i <= n; i ++) {
        int mx = min (n, 4 * i - 1);
        int good = n - pre[mx];
        good += mp[i];
        if (2 * i <= n) good += mp[2 * i];
        if (3 * i <= n) good += mp[3 * i];
        
        if (good + k >= n) {
            ans = i;
        } 
    }

    cout << ans << '\n';
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}