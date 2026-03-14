#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, q;
    cin >> n >> q;
    vector<int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    ranges :: sort (a | views::drop(1) | views::take(n)); 
    int x, y;
    while (q --) {
        cin >> x >> y;

        int l = lower_bound(a.begin() + 1, a.end(), x) - a.begin();
        if (l > n) {
            cout << x + y - 1 << endl;
            continue;
        }
        int mn = l;
        int r = n;
        // cout << l << ' ' << r << ' ' << mn << endl;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int an = a[mid] - x - (mid - mn);
            // cout << mid << ' ' << an << endl;
            if (an < y) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            // cout << l << endl;
        }
        
        if (l > n) {
            cout << x + y - 1 + (n - mn + 1) << endl;
        } else {
            cout << x + y - 1 + (l - mn) << endl;
        }
    }
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