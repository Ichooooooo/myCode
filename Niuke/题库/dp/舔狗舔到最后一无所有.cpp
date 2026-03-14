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
    vector<int> a(n + 1), b(n + 1);

    a[1] = 0, b[1] = 3;
    for (int i  = 2; i <= n; i ++) {
        a[i] = b[i - 1];
        b[i] = (a[i - 1] + b[i - 1]) * 2;
    }
    cout << a[n] + b[n] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}