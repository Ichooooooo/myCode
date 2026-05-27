#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, q;  cin >> n >> q;
    
    vector <int> a (n + 1), b (n + 1), mxa(n + 2);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int j = 1; j <= n; j ++) cin >> b[j];

    for (int i = n; i >= 1; i --) {
        mxa[i] = max (mxa[i + 1], mxa[i]);
        mxa[i] = max (mxa[i], a[i]);
        mxa[i] = max (mxa[i], b[i]);
    }

    vector  <int> pre (n + 1);
    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + mxa[i];
    }

    int l, r;
    while (q --) {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << ' ';
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