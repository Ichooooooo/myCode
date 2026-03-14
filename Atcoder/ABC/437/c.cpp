//贪心加公式，看题解

#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    ll x, y, sum = 0;

    for (int i = 1; i <= n; i ++) {
        cin >> x >> y;
        sum += y;
        a[i] = x + y;
    }
    ranges::sort(a);
    int p = 1, tx = 0;
    while (tx + a[p] <= sum) {
        tx += a[p];
        p ++;
    }
    cout << p - 1 << endl;
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