#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;  cin >> n >> m;

    vector <PII> a (n + 1);
    vector <int> pre (n + 1), ans (n + 1);
    for (int i = 1; i <= n; i ++)  {
        cin >> a[i].first;
        a[i].second = i;
    }

    ranges :: sort (a | views :: drop(1));

    vector <int> b (n + 2), c (n + 2);
    // b : 自加次数, c : 区间加

    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + a[i].first;
    }

    for (int i = 1; i < n; i ++) {
        int pos = lower_bound(a.begin() + 1 + i, a.end(), PII {m - a[i].first + 1, LLONG_MIN}) - a.begin();
        int l = pos - 1 - i, r = n - pos + 1;

        ans[i] += l * a[i].first;  b[i + 1] ++;  b[pos] --;
        ans[i] -= pre[n] - pre[pos - 1]; c[pos] -= a[i].first; 
    }

    unordered_map <int, int> mp;
    int cnt = 0, nm = 0;
    for (int i = 1; i <= n; i ++) {
        cnt = cnt + b[i];
        nm = nm + c[i];
        
        ans[i] = ans[i] + cnt * a[i].first + nm;mp[a[i].second] = ans[i];
    }

    for (int i = 1; i <= n; i ++) cout << mp[i] << ' ';
    cout << endl;
    
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