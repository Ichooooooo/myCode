#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int s, k, m;
    cin >> s >> k >> m;
    if (k >= s) {
        cout << max(s - m % k, 0LL) << endl;
    } else {
        int n = m / k;
        if (n % 2 == 0) {
            cout << s - m % k << endl;
        } else {
            cout << k - m % k << endl;
        }
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