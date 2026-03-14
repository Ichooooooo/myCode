#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, h;
    cin >> n >> m >> h;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int b, c;
    vector <int> cur(n + 1), time(n + 1, -1);
    cur = a;
    int lt = 0;
    for (int i = 1; i <= m; i ++) {
        
        cin >> b >> c;
        if (time[b] <= lt) cur[b] = a[b];

        cur[b] += c;
        time[b] = i;

        if (cur[b] > h) {
            lt = i;
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (lt < time[i]) {
            cout << cur[i] << ' ';
        } else {
            cout << a[i] << ' ';
        }
    }

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