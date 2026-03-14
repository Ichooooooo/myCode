#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    // int n; cin >> n;
    // vector <int> a (n);
    // for (int & i : a) cin >> i;

    // sort (a.begin(), a.end());

    // int pos = (4 * n + 4) / 5;
    // int t = a[pos - 1];

    // // int p = lower_bound(a.begin(), a.end(), t) - a.begin();
    
    // // // cout << p << ' ' << a[p] << ' ';
    // // cout << accumulate(a.begin() + p, a.end(), 0LL) << '\n';

    // int sum = 0;
    // for (int i = 0; i < n; i ++) {
    //     if (a[i] >= t) {
    //         sum += a[i];
    //     }
    // }

    // cout << sum << '\n';
    
    int n; cin >> n;
    map <int, int> mp;
    int t;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        mp[t] ++;
    }

    int pos = (4 * n + 4) / 5, tar = -1, ans = 0, cnt = 0;
    for (auto [a, b] : mp) {
        if (tar == -1) {
            cnt += b;
            if (cnt >= pos) {ans += a * b; tar = a;}
        } else {
            ans += a * b;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}