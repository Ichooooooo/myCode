#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

bool check(vector<ll> a, ll tar, ll b) {
    int n = a.size();
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += min(a[i], b);
        if (ans > tar) {
            return false;
        }
    }
    return true;
}

void solve(){   
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int & i : a) cin >> i;
    ll sum = 0, ok = 1;
    for (int i = 0; i < n; i ++) {
        sum += a[i];
        if (sum > m) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        cout << "infinite" << endl;
    } else {
        int l = 0, r = ranges::max(a);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(a, m, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}