#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <int> a (n + 1);
    a[1] = a[2] = 1;

    auto dg = [&] (int m) -> int{
        a[m] = a[m - 1] + a[m - 2];
        return m + 1;
    };

    int m = 3;
    while (m <= n) {
        m = dg(m);
    }

    cout << a[n] << endl;
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