#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<int> a (n + 1);
    vector<int> pr(n + 1), py(n + 1), pw(n + 1);

    for (int i = 1; i <= n; i ++) {
        pr[i] = pr[i - 1];
        py[i] = py[i - 1];
        pw[i] = pw[i - 1];
        if (s[i - 1] == 'r') {a[i] = 2; pr[i] ++;}
        else if (s[i - 1] == 'y') {a[i] = 1; py[i] ++;}
        else {a[i] = 0, pw[i] ++;}
    }

    if (n * 2 < k) {
        cout << -1 << endl;
        return;
    } 
    
    auto check = [&] (int mid) -> bool {
        int ok = 1, cnt = 0, mx = 0, cur;
        int x, y, z;
        for (int i = mid; i <= n; i ++) {
            x = pr[i] - pr[i - mid];
            y = py[i] - py[i - mid];
            z = pw[i] - pw[i - mid];
            if (x < y) swap(x, y);
            z = min (z, m);
            cur = 2 * x + y + 2 * z;
            mx = max (mx, cur);
        }
        if (mx >= k) {
            return true;
        } else {
            return false;
        }
    };

    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (check (mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (l > n) {
        cout << -1 << endl;
    } else {
        cout << l << endl;
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

// 滑动窗口

void solve(){  
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector <int> r(n + 1), y(n + 1), w(n + 1);

    if (2 * n < k) {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 1; i <= n; i ++) {
        r[i] = r[i -1]; y[i] = y[i - 1]; w[i] = w[i - 1];
        if (s[i - 1] == 'r') r[i] ++;
        else if (s[i - 1] == 'y') y[i] ++;
        else w[i] ++;
    }

    int l = 1, len = LLONG_MAX;
    for (int i = 1; i <= n; i ++) {
        int rr = r[i] - r[l - 1], yy = y[i] - y[l - 1], ww = w[i] - w[l - 1];
        int sum; 
        while (l <= i) {
            sum = max (2 * rr + yy, 2 * yy + rr) + 2 * min(ww, m);
            if (sum >= k) {
                rr -= (s[l - 1] == 'r');
                yy -= (s[l - 1] == 'y');
                ww -= (s[l - 1] == 'w');
                l ++;
                len = min (len, i - l + 1);
            } else {
                break;
            }
        }
    }

    if (len == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << len + 1 << endl;
    }
}